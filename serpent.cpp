#include "serpent.h"
#include <SFML\Graphics.hpp>

//Constructor
Snake::Snake(float startX, float startY) : m_Position(startX, startY) {

	m_Snake.setSize(Vector2f(35, 35));
	m_Snake.setFillColor(Color::Green);
	m_Snake.setPosition(m_Position);
}

FloatRect Snake::getPosition() {
	return m_Snake.getGlobalBounds();
}

RectangleShape Snake::getShape() {
	return m_Snake;
}

Vector2f Snake::getCenter() {
	return m_Position;
}


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
bool Snake::isMoving() {
	if (m_MoveRight == true || m_MoveLeft == true || m_MoveUp == true || m_MoveDown == true) {
		return true;
	}
}

void Snake::resetPositionRight() {
	m_Position.x = 0;
	m_Position.y = m_Snake.getPosition().y;
}

void Snake::resetPositionLeft() {
	m_Position.x = 1900;
	m_Position.y = m_Snake.getPosition().y;
}

void Snake::resetPositionUp() {
	m_Position.x = m_Snake.getPosition().x;
	m_Position.y = 1200;
}

void Snake::resetPositionDown() {
	m_Position.x = m_Snake.getPosition().x;
	m_Position.y = 0;
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