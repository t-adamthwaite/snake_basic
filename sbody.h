#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace sf;
using namespace std;

class Sbody {
private:

	vector<RectangleShape> m_Sbody;
	Vector2f m_Position;

public:
	Sbody(float startX, float startY, int score);
	FloatRect getPosition(vector<RectangleShape> m_Sbody);
	RectangleShape getShape();
	vector<RectangleShape> getPieces();
	Vector2f getCenter(int i);


	void followHead(Vector2f headSegment, vector<RectangleShape> currentBody);
	void grow(int score, float headX, float headY);
};