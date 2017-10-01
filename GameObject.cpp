#include "GameObject.h"

std::vector<GameObject*> GameObject::gameObjects;
std::map<char*, GameObject*> GameObject::gameObjectsByTag;

GameObject::GameObject() {
	name = "gameObject";
}

GameObject::~GameObject() {
}

void GameObject::SetEnabled(bool value) {
	isEnabled = value;
	if (isEnabled)
		OnEnabled();
}

bool GameObject::IsEnabled() {
	return isEnabled;
}

void GameObject::OnEnabled() {
}

void GameObject::Update(double deltaTime) {
}

void GameObject::Draw(sf::RenderWindow &window) {
}

void GameObject::Create(GameObject* gameObject, char* tag = nullptr) {
	if (tag != nullptr) {
		if (gameObjectsByTag.count(tag)) {
			delete gameObject;
			return;
		}

		gameObject->tag = tag;
		gameObjectsByTag.insert({ tag, gameObject });
	}

	gameObjects.push_back(gameObject);
}

void GameObject::Destroy(GameObject* gameObject) {
	int position = 0;
	for (auto _gameObject : gameObjects) {
		if (_gameObject == gameObject) {
			if (gameObjectsByTag.count(gameObject->tag)) {
				gameObjectsByTag.erase(gameObject->tag);
			}

			gameObjects.erase(gameObjects.begin() + position);
			delete gameObject;
			break;
		}

		position++;
	}
}

void GameObject::UpdateAll(double deltaTime) {
	for (auto gameObject : gameObjects)
		if (gameObject->isEnabled)
			gameObject->Update(deltaTime);
}

void GameObject::DrawAll(sf::RenderWindow &window) {
	for (auto gameObject : gameObjects)
		if (gameObject->isEnabled)
			gameObject->Draw(window);
}