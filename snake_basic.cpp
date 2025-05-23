#include "serpent.h"
#include "target.h"
#include "sbody.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <random>
#include <time.h>
#include <SFML\Graphics.hpp>

using namespace std;

int main() {
	VideoMode vm(1920, 1200);
	RenderWindow window(vm, "Snake", Style::Fullscreen);
	window.setFramerateLimit(10);

	srand(time(0));

	int score = 0;

	Snake snake(1920 / 2, 1200 / 2);
	Sbody body(snake.getPosition().left, snake.getPosition().top + 20, 0);
	Target target(rand() % 1900, rand() % 1180);

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
		int msgt = gameTotal.asMilliseconds();
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

		Vector2f oldPosition = snake.getCenter();

		Time dt = clock.restart();
		snake.update(dt);

		//Score to screen
		std::stringstream ss;
		ss << "Score :   " << score;
		scores.setString(ss.str());

		//Teleport across screen
		if (snake.getPosition().left > 1920) {
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


		vector<RectangleShape> currentBody = body.getPieces();

		//Body follows head
		if (score >= 0) {
			Vector2f newPosition = snake.getCenter();
			if (snake.isMoving() == true) {
				body.followHead(oldPosition, currentBody);
			}
		}

		if (snake.getPosition().intersects(target.getPosition())) {
			int x = (rand() % 1900);
			int y = (rand() % 1180);
			target.reset(x, y);
			score++;
			body.grow(score, -80, -80);
		}

		currentBody = body.getPieces();

		for (int i = 0; i < currentBody.size(); i++) {
			if (snake.getPosition().intersects(currentBody[i].getGlobalBounds())) {
				snake.stopDown();
				snake.stopUp();
				snake.stopRight();
				snake.stopLeft();
			}
		}

		//Draw
		window.clear();
		window.draw(snake.getShape());
		for (int i = 0; i < currentBody.size(); i++) {
			window.draw(currentBody[i]);
		}
		window.draw(target.getShape());
		window.draw(scores);
		window.display();
		
	}
}