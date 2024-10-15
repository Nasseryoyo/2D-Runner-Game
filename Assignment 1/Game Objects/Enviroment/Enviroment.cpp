#include "Game Objects/Enviroment/Enviroment.h"

extern int windowWidth;
extern int windowHeight;

Enviroment::Enviroment()
{
	// Create 5 clouds

	Cloud cloud(windowWidth * 0.9, windowHeight * 0.70);
	clouds.push_back(cloud);


	// Create 3 mountains
	Mountain mountain(windowWidth, 0, 600, 500);
	mountains.push_back(mountain);

}

Enviroment::~Enviroment()
{
}

void Enviroment::update(float deltaTime)
{
	// Update all clouds
	for (int i = 0; i < clouds.size(); i++)
	{
		clouds[i].update(deltaTime);
	}
	// Update all mountains
	for (int i = 0; i < mountains.size(); i++)
	{
		mountains[i].update(deltaTime);

	}
	ground.update(deltaTime);
}

void Enviroment::render()
{

	// Render all mountains
	for (int i = 0; i < mountains.size(); i++)
	{
		mountains[i].render();
	}
	// Render all clouds
	for (int i = 0; i < clouds.size(); i++)
	{
		clouds[i].render();
	}

	ground.draw();

}



