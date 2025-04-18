#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Target {
private:

	RectangleShape m_Target;
	Vector2f m_Position;

public:
	Target(float startX, float startY);
	RectangleShape getShape();
	FloatRect getPosition();

	void collision();
	
	void update(Time dt);
};