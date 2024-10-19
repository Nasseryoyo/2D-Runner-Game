#pragma once
class Mountain
{
public:
	Mountain();
	Mountain(float x, float y, float width, float height);
	~Mountain();
	float getX();
	float getWidth();

	void update(float deltaTime);
	void render();
private:
	float x, y;
	float height;
	float width;
	float speed;
};

