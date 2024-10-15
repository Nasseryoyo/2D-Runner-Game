#pragma once
#include <vector>
#include <Game Objects/Collectibles/Coin.h>
class CollectibleManager {
public:
	CollectibleManager();
	void update(float deltaTime);
	void render();
	void addCollectible(float startX, float startY);
	const std::vector<Coin>& getCollectibles() const;
private:
	std::vector<Coin> collectibles;

};