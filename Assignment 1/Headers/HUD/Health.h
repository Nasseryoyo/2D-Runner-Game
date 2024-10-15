#pragma once

class Health
{
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
private:
	int lives;
	void drawHeart(float x, float y, float size);  // Add this line
public:
	Health();
	void setLives(int lives);
	void drawHealth();

};