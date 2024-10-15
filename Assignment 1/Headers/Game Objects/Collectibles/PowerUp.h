#pragma once
class PowerUp
{
public:
	PowerUp();
	~PowerUp();
	PowerUp(float startX, float startY);
	void update(float deltaTime);
	void render();
	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;
	int getPowerUpType() const;
	void setPowerUpType(int type);
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
	float dx;
	float speed;
	int powerUpType;
	bool collected;
};

