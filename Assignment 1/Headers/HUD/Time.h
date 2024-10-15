#pragma once
class Time
{
private:
	float gameTime;

public:
	Time();
	void updateTime(float deltaTime);
	void drawTime();
	float getTime();
};

