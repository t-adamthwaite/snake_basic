#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace sf;
using namespace std;

class Sbody {
private:

	vector<RectangleShape> m_Sbody;
	Vector2f m_Position;

	float m_Speed = 480.0f;

public:
	Sbody(float startX, float startY, int score);
	FloatRect getPosition(vector<RectangleShape> m_Sbody);
	RectangleShape getShape();
	vector<RectangleShape> getPieces();
	Vector2f getCenter(int score);


	void followHead(float dt, Vector2f headSegment);
	void followBody(Vector2f prevSegment);

	void grow(int score, float headX, float headY);
	void update(Time dt);
};