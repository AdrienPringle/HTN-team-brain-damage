#include "LevelLoader.h"
#include "Game/GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/GameEntities/ObstacleEntity.h"

using namespace Game;
LevelLoader::LevelLoader()
{
	sf::Vector2f positions[2] = { sf::Vector2f(-100.f, 50.f), sf::Vector2f(0.f, -50.f) };
	sf::Vector2f sizes[2] = { sf::Vector2f(-100.f, 50.f), sf::Vector2f(0.f, -50.f) };
	GameEngine::eTexture::type textures[2] = { GameEngine::eTexture::Start , GameEngine::eTexture::Start };

}

void LevelLoader::CreateObstacle() {

	ObstacleEntity* obstacle = new ObstacleEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

	obstacle->SetPos(sf::Vector2f(positions[0]));
	obstacle->SetSize(sf::Vector2f(sizes[0]));

	obstacle->setTexture(textures[0]);


}



void Update() {

}