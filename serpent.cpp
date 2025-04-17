#include "serpent.h"
#include <SFML\Graphics.hpp>

//Constructor
Snake::Snake(float startX, float startY) : m_Position(startX, startY) {

	m_Snake.setSize(Vector2f(10, 10));
	m_Snake.setPosition(m_Position);
}

FloatRect Snake::getPosition() {
	return m_Snake.getGlobalBounds();
}

RectangleShape Snake::getShape() {
	return m_Snake;
}

//Vector2f resetPosition() {
	//Figure out how to teleport to opposite side later
//}

float Snake::getSpeed() {
	return m_Speed;
}

void Snake::moveRight() {
	m_MoveRight = true;
}
void Snake::moveLeft() {
	m_MoveLeft = true;
}
void Snake::moveUp() {
	m_MoveUp = true;
}
void Snake::moveDown() {
	m_MoveDown = true;
}

void Snake::stopRight() {
	m_MoveRight = false;
}
void Snake::stopLeft() {
	m_MoveLeft = false;
}
void Snake::stopUp() {
	m_MoveUp = false;
}
void Snake::stopDown() {
	m_MoveDown = false;
}


void Snake::grow() {
	//MORE HERE LATER
}


void Snake::update(Time dt) {
	if (m_MoveRight) {
		m_Position.x += m_Speed * dt.asSeconds();
	}
	if (m_MoveLeft) {
		m_Position.x -= m_Speed * dt.asSeconds();
	}
	if (m_MoveUp) {
		m_Position.y -= m_Speed * dt.asSeconds();
	}
	if (m_MoveDown) {
		m_Position.y += m_Speed * dt.asSeconds();
	}
	m_Snake.setPosition(m_Position);
}