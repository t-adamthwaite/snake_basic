#include "serpent.h"
#include "target.h"
#include <sstream>
#include <cstdlib>
#include <random>
#include <time.h>
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;

int main() {
	VideoMode vm(1920, 1200);
	RenderWindow window(vm, "Snake", Style::Fullscreen);

	srand(time(0));

	int score = 0;

	Snake snake(1920 / 2, 1200 / 2);
	Target target(rand() % 1960, rand() % 1180);

	Text scores;
	Font font;
	font.loadFromFile("Fonts/DS-DIGIT.ttf");
	scores.setFont(font);
	scores.setCharacterSize(75);
	scores.setFillColor(Color::White);
	scores.setPosition(20, 20);


	//Clock
	Clock clock;

	//Game Loop
	while (window.isOpen()) {

		Time gameTotal = clock.getElapsedTime();
		Time lastHit;
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

		//Score to screen
		std::stringstream ss;
		ss << "Score :   " << score;
		scores.setString(ss.str());

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

		if (snake.getPosition().intersects(target.getPosition()) /* && gameTotal.asSeconds() - lastHit.asSeconds() > 0.4*/) {
			int x = rand() % 1960;
			int y = rand() % 1180;
			target.reset(x, y);
			snake.grow();
			score++;
			//lastHit = gameTotal;

		}

		//Draw
		window.clear();
		window.draw(scores);
		window.draw(snake.getShape());
		window.draw(target.getShape());
		window.display();
	}


}