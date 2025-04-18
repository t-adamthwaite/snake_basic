#include "serpent.h"
#include "target.h"
#include <sstream>
#include <cstdlib>
#include <random>
#include <time.h>
#include <SFML\Graphics.hpp>

using namespace std;

int main() {
	VideoMode vm(1920, 1200);
	RenderWindow window(vm, "Snake", Style::Fullscreen);

	srand(time(0));

	int score = 0;

	Snake snake(1920 / 2, 1200 / 2);
	Target target(rand() % 1960, rand() % 1180);


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

		//Teleport across screen
		if (snake.getPosition().left > 1980) {
			snake.resetPositionRight();
		}

		if (snake.getPosition().left < 0) {
			snake.resetPositionLeft();
		}

		if (snake.getPosition().top < 0) {
			snake.resetPositionUp();
		}

		if (snake.getPosition().top > 1200) {
			snake.resetPositionDown();
		}

		//Draw
		window.clear();
		window.draw(snake.getShape());
		window.draw(target.getShape());
		window.display();
	}


}