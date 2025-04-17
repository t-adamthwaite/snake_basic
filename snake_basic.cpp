#include "serpent.h"
#include <sstream>
#include <cstdlib>
#include <SFML\Graphics.hpp>

int main() {
	VideoMode vm(1920, 1200);
	RenderWindow window(vm, "Snake", Style::Fullscreen);

	int score = 0;

	Snake snake(1920 / 2, 1200 / 2);


	//Clock
	Clock clock;

	//Game Loop
	while (window.isOpen()) {

		Time gameTotal = clock.getElapsedTime();
		Time lastPlayerInput;
		//Handle Inputs
		
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snake.moveRight();
			snake.stopLeft();
			snake.stopUp();
			snake.stopDown();
			//Teleport if past confines of screen
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snake.moveLeft();
			snake.stopRight();
			snake.stopUp();
			snake.stopDown();
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			snake.moveUp();
			snake.stopLeft();
			snake.stopRight();
			snake.stopDown();
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			snake.moveDown();
			snake.stopLeft();
			snake.stopRight();
			snake.stopUp();
		}
		
		//Update
		
		Time dt = clock.restart();
		snake.update(dt);

		//Draw
		window.clear();
		window.draw(snake.getShape());
		window.display();
	}


}