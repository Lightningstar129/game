#pragma once

#include "Engine/GameEngine.h"

class Firefly : public GameObject
{
public:
	//creates ship
	Firefly();

	//funtions overriden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite_;
	int fireTimer_ = 0;
};

typedef std::shared_ptr<Firefly> FireflyPtr;
