#pragma once
#include <vector>
#include <Game Objects/Enviroment/Stone.h>
class Ground {
public:
	Ground();
	void draw();
	void update(float deltaTime);
private:
	std::vector<Stone> stones;
};

