#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <map>

class GameObject {
public:
	GameObject();
	virtual ~GameObject();

	void SetEnabled(bool value);
	bool IsEnabled();
	virtual void OnEnabled();

	virtual void Update(double deltaTime);
	virtual void Draw(sf::RenderWindow &window);

	static void Create(GameObject* gameObject, char* tag);
	static void Destroy(GameObject* gameObject);

	static void UpdateAll(double deltaTime);
	static void DrawAll(sf::RenderWindow &window);

	sf::Vector2f position;
	sf::Sprite sprite;
	char* name;

protected:
	char* tag;

private:
	static std::vector<GameObject*> gameObjects;
	static std::map<char*, GameObject*> gameObjectsByTag;
	bool isEnabled;
};