#pragma once


class Stone {
public:
	Stone(float x, float y);
	void update(float deltaTime);
	void render();
	float x;
	float y;
};

