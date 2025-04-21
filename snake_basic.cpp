#include "serpent.h"
#include "target.h"
#include "sbody.h"
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
		float fdt = dt.asSeconds();
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

		Vector2f newPosition = snake.getCenter();
		body.follow(fdt, newPosition);

		if (snake.getPosition().intersects(target.getPosition())) {
			int x = (rand() % 1900);
			int y = (rand() % 1180);
			target.reset(x, y);
			//snake.grow(score);
			score++;
			

		}

		//Draw
		window.clear();
		window.draw(scores);
		window.draw(snake.getShape());
		window.draw(body.getShape());
		window.draw(target.getShape());
		window.display();
	}


}