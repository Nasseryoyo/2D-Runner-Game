#pragma once
#include <vector>

class Obstacle {
public:
	Obstacle(float startX, float startY, bool reverseDirection);
	void update(float deltaTime);
	void render();
	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;

private:
	float x, y;              // Position of the obstacle
	float width, height;     // Dimensions of the obstacle
	float speed;             // Speed at which the obstacle moves
	bool reverseDirection;   // Direction of the obstacle (upward or downward)
};

