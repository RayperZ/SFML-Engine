#pragma once
#include <SFML\Graphics.hpp>
#include "Input.h"

class Game {
public:
	Game();
	~Game();

	static void Initialize();
	
	static void Run(sf::RenderWindow &window);
	static void Update(double deltaTime);
	static void Draw(sf::RenderWindow &window);
};
