#pragma once

#include "Engine/GameEngine.h"
#include "Orb.h"

class OrbSpawner : public GameObject
{
public:
	void update(sf::Time& elapsed);
private:
	int timer_ = 0;
};

typedef std::shared_ptr<OrbSpawner> OrbSpawnerPtr;