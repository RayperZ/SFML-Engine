#pragma once
#include <SFML/Window.hpp>
#include <map>

class Input {
private:
	static bool Input::IsKeyboardActive(char* action);
	static bool Input::IsMouseActive(char* action);
	static bool Input::IsJoystickActive(char* action);

	class Helper {
	public:
		class Keyboard {
		public:
			Keyboard() {}
			Keyboard(sf::Keyboard::Key k) : active(false), key(k) {}
			bool active;
			sf::Keyboard::Key key;
		};

		class Mouse {
		public:
			bool active;
			sf::Mouse::Button button;

			Mouse() {}
			Mouse(sf::Mouse::Button b) : active(false), button(b) {}
		};
		class JoystickButton {
		public:
			int nPad;
			int button;
			bool active;

			JoystickButton() {}
			JoystickButton(int n, int b) : active(false), nPad(n), button(b) {}
		};
		class JoystickAxis {
		public:
			int nPad;
			int position;
			sf::Joystick::Axis axis;

			JoystickAxis() {}
			JoystickAxis(int n, sf::Joystick::Axis a) : position(0), nPad(n), axis(a) {}
		};
	};

	static std::map<char*, Helper::Keyboard> keyboardBinds;
	static std::map<char*, Helper::Mouse> mouseBinds;
	static std::map<char*, Helper::JoystickButton> joystickButtonBinds;
	static std::map<char*, Helper::JoystickAxis> joystickAxisBinds;

public:
	static void Initialize();
	static void Update();

	static void Bind(char* action, sf::Keyboard::Key key);
	static void Bind(char* action, sf::Mouse::Button button);
	static void Bind(char* action, int pad, sf::Joystick::Axis axis);
	static void Bind(char* action, int pad, int button);

	static bool IsBinded(char* action);
	static bool IsKeyboardBinded(char* action);
	static bool IsMouseBinded(char* action);
	
	static bool IsJoystickButtonBinded(char* action);
	static bool IsJoystickAxisBinded(char* action);
	static bool IsJoystickBinded(char* action);

	static int Action(char* action);
};
