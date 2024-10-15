#pragma once
#include <string>
#include <functional>

class Button
{
public:
	Button() = default;
	Button(std::string text, float x, float y, float width, float height);
	virtual ~Button() = default;
	void draw();
	bool isClicked(float mouseX, float mouseY);
	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;

private:
	std::string text;
	float x, y;  // Button position
	float width;  // Button width
	float height; // Button height

};


