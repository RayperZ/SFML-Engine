#include "Game.h"

Game::Game() {
	// sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Title", sf::Style::Fullscreen);
	sf::RenderWindow window(sf::VideoMode::VideoMode(128, 64), "Title");

	window.setVerticalSyncEnabled(true);
	// window.setMouseCursorVisible(false);
	// window.setFramerateLimit(60);

	Initialize();
	Run(window);
}

Game::~Game() {

}

void Game::Run(sf::RenderWindow &window) {
	sf::Clock clock;

	while (window.isOpen()) {
		sf::Event event;
		
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			else if (Input::Action("Close"))
				window.close();
		}

		Update(clock.restart().asSeconds());
		Draw(window);
	}
}

void Game::Initialize() {
	srand(static_cast<unsigned int>(time(nullptr)));

	Input::Initialize();
}

void Game::Update(double deltaTime) {
	Input::Update();
	 
	// printf("%d\n", static_cast<int>(floor(timeDelta * 3600.0f)));
}

void Game::Draw(sf::RenderWindow &window) {
	window.clear();

	// ...

	window.display();
}