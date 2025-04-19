#include "target.h"
#include <SFML\Graphics.hpp>


Target::Target(float startX, float startY) : m_Position(startX, startY) {

	m_Target.setSize(Vector2f(20, 20));
	m_Target.setPosition(m_Position);
}

RectangleShape Target::getShape() {
	return m_Target;
}

FloatRect Target::getPosition() {
	return m_Target.getGlobalBounds();
}

void Target::reset(int x, int y) {
	m_Target.setPosition(x, y);
}

void Target::update(Time dt) {
	//More here later
}