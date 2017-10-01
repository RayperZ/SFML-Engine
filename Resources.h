#pragma once
#include <SFML\Graphics.hpp>
#include <map>

class Resources {
public:
	Resources();
	~Resources();

	static sf::Texture* LoadTexture(char* filePath);
	static void RemoveTexture(char* filePath);

	static sf::Sprite LoadSprite(char* filePath);

private:
	static std::map<char*, sf::Texture*> textures;
};