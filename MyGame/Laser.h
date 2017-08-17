#pragma once

#include "Engine/GameEngine.h"

class Laser : public GameObject
{
public:
	//creates laser
	Laser(sf::Vector2f pos);

	//functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Laser> LaserPtr;
