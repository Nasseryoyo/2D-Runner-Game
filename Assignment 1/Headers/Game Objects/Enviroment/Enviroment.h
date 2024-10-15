#pragma once
#include "Game Objects/Enviroment/Cloud.h"
#include <vector>
#include "Game Objects/Enviroment/Mountain.h"
#include "Game Objects/Enviroment/Ground.h"
class Enviroment
{
public:
	Enviroment();
	~Enviroment();

	void update(float deltaTime);
	void render();
private:
	std::vector<Cloud> clouds;
	std::vector<Mountain> mountains;
	Ground ground;
};

