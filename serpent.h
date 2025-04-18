#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Snake {
private:
	//Snake sprite
	RectangleShape m_Snake;
	Vector2f m_Position;
	//Movement
	float m_Speed = 500.0f;
	bool m_MoveRight = false;
	bool m_MoveLeft = false;
	bool m_MoveUp = false;
	bool m_MoveDown = false;

public:
	Snake(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();

	float getSpeed();

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	void stopRight();
	void stopLeft();
	void stopUp();
	void stopDown();

	void resetPositionRight();
	void resetPositionLeft();
	void resetPositionUp();
	void resetPositionDown();

	void grow();

	void update(Time dt);
};