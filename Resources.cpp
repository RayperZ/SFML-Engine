#include "Resources.h"

std::map<char*, sf::Texture*> Resources::textures;

Resources::Resources() {
}

Resources::~Resources() {
}

sf::Texture* Resources::LoadTexture(char* filePath) {
	if (textures.count(filePath))
		return textures[filePath];

	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(filePath);
	
	textures.insert({ filePath, texture });

	return texture;
}

void Resources::RemoveTexture(char* filePath) {
	if (textures.count(filePath)) {
		delete textures[filePath];
		textures.erase(filePath);
	}
}

sf::Sprite Resources::LoadSprite(char* filePath) {
	return sf::Sprite(*LoadTexture(filePath));
}