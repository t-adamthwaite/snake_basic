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

Vector2f Sbody::getCenter(int i) {
	return m_Sbody[i].getPosition();
}

void Sbody::followHead(float dt, Vector2f headSegment, vector<RectangleShape> currentBody) {
			m_Sbody[0].setPosition(headSegment);
			for (int i = 1; i < m_Sbody.size(); i++) {
				m_Sbody[i].setPosition(currentBody[i-1].getPosition().x, currentBody[i - 1].getPosition().y);
			}
}

void Sbody::grow(int score, float headX, float headY) {
	m_Sbody.push_back(RectangleShape(Vector2f(20, 20)));
	m_Sbody[score].setPosition(headX, headY);
}