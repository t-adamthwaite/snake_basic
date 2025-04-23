#include "sbody.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

Sbody::Sbody(float startX, float startY, int score) : m_Position(startX, startY) {

	m_Sbody.push_back(RectangleShape(Vector2f(20, 20)));
	m_Sbody[score].setPosition(m_Position);

}

FloatRect Sbody::getPosition(vector<RectangleShape> m_Sbody) {
	for (int i = 0; i < m_Sbody.size(); i++) {
		return m_Sbody[i].getGlobalBounds();
	}
}

RectangleShape Sbody::getShape() {
	for (int i = 0; i < m_Sbody.size(); i++) {
		return m_Sbody[i];
	}
}

vector<RectangleShape> Sbody::getPieces() {
	return m_Sbody;
}

Vector2f Sbody::getCenter(int score) {
	return m_Sbody[score].getPosition();
}

void Sbody::followHead(float dt, Vector2f headSegment) {
	for (int i = 0; i < m_Sbody.size(); i++) {
		if (i == 0) {
			float X = headSegment.x;
			float Y = headSegment.y;
			m_Sbody[i].setPosition(X, Y);
		}
	}
}

void Sbody::followBody(Vector2f prevSegment) {
	for (int i = 1; i < m_Sbody.size(); i++) {
		if (i >= 1) {
			float X = prevSegment.x;
			float Y = prevSegment.y;
			m_Sbody[i].setPosition(X, Y);
		}
	}
}

void Sbody::grow(int score, float headX, float headY) {
	m_Position.x = headX;
	m_Position.y = headY;
	m_Sbody.push_back(RectangleShape(Vector2f(20, 20)));
	m_Sbody[score].setPosition(m_Position);
}

void update() {

}