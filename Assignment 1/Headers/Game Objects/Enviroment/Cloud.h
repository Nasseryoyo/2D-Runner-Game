#pragma once
class Cloud
{
public:
	Cloud();
	Cloud(float x, float y);
	~Cloud();
	float getX();
	float getWidth();

	void update(float deltaTime);
	void render();
private:
	float x, y;
	float speed;
};

