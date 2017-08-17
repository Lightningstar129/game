#include "GameScene.h"
#include "Firefly.h"
#include "OrbSpawner.h"
#include "Score.h"
#include "GameOverScene.h"
#include "ShardSpawner.h"

GameScene::GameScene()
{
	FireflyPtr firefly = std::make_shared<Firefly>();
	addGameObject(firefly);

	OrbSpawnerPtr orbSpawner = std::make_shared<OrbSpawner>();
	addGameObject(orbSpawner);

	ShardSpawnerPtr shardSpawner = std::make_shared<ShardSpawner>();
	addGameObject(shardSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);
}

int GameScene::getScore()
{
	return score_;
}

void GameScene::increaseScore()
{
	++score_;
}

int GameScene::getLives()
{
	return lives_;
}

void GameScene::decreaseLives()
{
	--lives_;

	if (lives_ == 0)
	{
		GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(score_);
		GAME.setScene(gameOverScene);
	}
}
