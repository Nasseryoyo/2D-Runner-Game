#pragma once
class Coin
{
public:
	Coin();
	~Coin();
	Coin(float startX, float startY);
	void update(float deltaTime);
	void render();
	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;
	void setX(float x);
	void setY(float y);
	void setWidth(float width);
	void setHeight(float height);
	void setCollected(bool flag);

private:
	float x;
	float y;
	float width;
	float height;
	float speed;
	bool collected;
};

