#pragma once
#include <vector>
#include <Game Objects/Collectibles/Coin.h>
class CollectibleManager {
public:
	CollectibleManager();
	void update(float deltaTime);
	void render();
	void addCollectible(float startX, float startY);
	std::vector<Coin>& getCollectibles();
private:
	std::vector<Coin> collectibles;

};