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

void Sbody::follow(float dt, Vector2f headSegment) {
	for (int i = 0; i < m_Sbody.size(); i++) {
		if (i == 0) {
			float X = headSegment.x;
			float Y = headSegment.y;
			m_Position.x = X;
			m_Position.y = Y;
			/*if (X > m_Sbody[i].getPosition().x) {
				m_Position.x = m_Sbody[i].getPosition().x + m_Speed * dt;
			}
			if (X < m_Sbody[i].getPosition().x) {
				m_Position.x = m_Sbody[i].getPosition().x - m_Speed * dt;
			}
			if (Y > m_Sbody[i].getPosition().y) {
				m_Position.y = m_Sbody[i].getPosition().y + m_Speed * dt;
			}
			if (Y < m_Sbody[i].getPosition().y) {
				m_Position.y = m_Sbody[i].getPosition().y - m_Speed * dt;
			}*/
			m_Sbody[i].setPosition(m_Position);
		}
		/*else {
			float X = m_Sbody[i - 1].getPosition().x;
			float Y = m_Sbody[i - 1].getPosition().y;
			if (X > m_Sbody[i].getPosition().x) {
				m_Position.x = m_Sbody[i].getPosition().x + m_Speed * dt;
			}
			if (X < m_Sbody[i].getPosition().x) {
				m_Position.x = m_Sbody[i].getPosition().x - m_Speed * dt;
			}
			if (Y > m_Sbody[i].getPosition().y) {
				m_Position.y = m_Sbody[i].getPosition().y + m_Speed * dt;
			}
			if (Y < m_Sbody[i].getPosition().y) {
				m_Position.y = m_Sbody[i].getPosition().y - m_Speed * dt;
			}
			m_Sbody[i].setPosition(m_Position);
		}*/
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