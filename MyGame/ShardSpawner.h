#pragma once

#include "Engine/GameEngine.h"
#include "Shard.h"

class ShardSpawner : public GameObject
{
public:
	void update(sf::Time& elapsed);
private:
	int timer_ = 0;
};

typedef std::shared_ptr<ShardSpawner> ShardSpawnerPtr;
