#include "Input.h"

std::map<char*, Input::Helper::Keyboard> Input::keyboardBinds;
std::map<char*, Input::Helper::Mouse> Input::mouseBinds;
std::map<char*, Input::Helper::JoystickButton> Input::joystickButtonBinds;
std::map<char*, Input::Helper::JoystickAxis> Input::joystickAxisBinds;

void Input::Initialize() {
	Bind("Close", sf::Keyboard::Escape);
}

void Input::Update() {
	for (auto &bind : keyboardBinds)
		bind.second.active = sf::Keyboard::isKeyPressed(bind.second.key);

	for (auto &bind : mouseBinds)
		bind.second.active = sf::Mouse::isButtonPressed(bind.second.button);

	for (auto &bind : joystickButtonBinds)
		bind.second.active = sf::Joystick::isButtonPressed(bind.second.nPad, bind.second.button);

	for (auto &bind : joystickAxisBinds)
		bind.second.position = sf::Joystick::getAxisPosition(bind.second.nPad, bind.second.axis);
}

void Input::Bind(char* action, sf::Keyboard::Key key) {
	if (IsKeyboardBinded(action)) keyboardBinds[action] = key;
	else keyboardBinds.insert({ action, key });

	printf("Binded '%s'", action);
}
void Input::Bind(char* action, sf::Mouse::Button button) {
	if (IsMouseBinded(action)) mouseBinds[action] = button;
	else mouseBinds.insert({ action, button });
}
void Input::Bind(char* action, int pad, sf::Joystick::Axis axis) {
	if (IsJoystickAxisBinded(action)) joystickAxisBinds[action] = { pad, axis };
	else joystickAxisBinds.insert({ action, {pad, axis} });
}
void Input::Bind(char* action, int pad, int button) {
	if (IsJoystickButtonBinded(action)) joystickButtonBinds[action] = { pad, button };
	else joystickButtonBinds.insert({ action, {pad, button} });
}

bool Input::IsBinded(char* action) {
	return IsKeyboardBinded(action) || IsMouseBinded(action) || IsJoystickBinded(action);
}
bool Input::IsKeyboardBinded(char* action) {
	return keyboardBinds.count(action);
}
bool Input::IsMouseBinded(char* action) {
	return mouseBinds.count(action);
}

bool Input::IsJoystickBinded(char* action) {
	return IsJoystickButtonBinded(action) || IsJoystickAxisBinded(action);
}
bool Input::IsJoystickButtonBinded(char* action) {
	return joystickButtonBinds.count(action);
}
bool Input::IsJoystickAxisBinded(char* action) {
	return joystickAxisBinds.count(action);
}

bool Input::IsKeyboardActive(char* action) {
	return keyboardBinds[action].active;
}
bool Input::IsMouseActive(char* action) {
	return mouseBinds[action].active;
}
bool Input::IsJoystickActive(char* action) {
	return (IsJoystickAxisBinded(action) ? joystickAxisBinds[action].position : joystickButtonBinds[action].active);
}

int Input::Action(char* action) {
	if (IsKeyboardBinded(action)) return IsKeyboardActive(action);
	if (IsMouseBinded(action)) return IsMouseActive(action);
	if (IsJoystickBinded(action)) return IsJoystickActive(action);
	return false;
}
