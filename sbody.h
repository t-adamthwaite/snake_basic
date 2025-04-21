#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace sf;
using namespace std;

class Sbody {
private:

	vector<RectangleShape> m_Sbody;
	Vector2f m_Position;

	float m_Speed = 500.0f;

public:
	Sbody(float startX, float startY, int score);
	FloatRect getPosition(vector<RectangleShape> m_Sbody);
	RectangleShape getShape();

	void follow(float dt, Vector2f headSegment);
	void grow();
	void update(Time dt);
};