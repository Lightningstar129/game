#include "Orb.h"
#include "Explosion.h"
#include "GameScene.h"

//const float SPEED = 0.25f;

Orb::Orb(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Art/half_darkness.png"));
	sprite_.setPosition(pos);
	assignTag("orb");
	setCollisionCheckEnabled(true);
	// rand			multiplier	SPEED
	// 0			0			lowest
	// RAND_MAX/4	1/4			quarter speed
	// RAND_MAX/2	1/2			half speed
	// RAND_MAX     1			full speed
	//SPEED = (float)rand()    RAND_MAX
	float percentagex = (1.0 / RAND_MAX)*rand();
	float percentagey = (1.0 / RAND_MAX)*rand();
	// pct	SPEEDx	SPEEDy
	// 0    .01		0		-.25
	// .5   .13		.125	0
	// 1    .25		.25		.25
	SPEEDx = ((0.24 / 1)*percentagex) + 0.01;
	SPEEDy = ((1/2)*percentagey) - 0.25;
}

void Orb::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Orb::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		makeDead();
	}
	sf::Vector2u size = GAME.getRenderWindow().getSize();
	if (pos.y < sprite_.getGlobalBounds().top * -1 || pos.y > size.y)
	{
		
		if (i == 0)
		{
			a++;
		}
		if (i == 1)
		{
			a = 0;
		}
		i = a;
	}
	if (i == 1)
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEEDx * msElapsed, pos.y + SPEEDy * msElapsed)); //goes down
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEEDx * msElapsed, pos.y - SPEEDy * msElapsed));  //goes up
	}
}

sf::FloatRect Orb::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}
void Orb::handleCollision(GameObject& otherGameObject)
{
	/*ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
	explosion->setOriginMode(OriginMode::TopMiddle);
	GAME.getCurrentScene().addGameObject(explosion);*/
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	
	if (otherGameObject.hasTag("firefly"))
	{
		scene.decreaseLives();
		makeDead();
	}
}
