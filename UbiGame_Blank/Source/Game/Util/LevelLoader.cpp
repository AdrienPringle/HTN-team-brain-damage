#include "LevelLoader.h"
#include "Game/GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/GameEntities/ObstacleEntity.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include "Game/GameEntities/BlobEntity.h"

using namespace Game;
////level 1
sf::Vector2f positions[2] = { sf::Vector2f(200.f, 50.f), sf::Vector2f(0.f, 50.f) };
sf::Vector2f sizes[2] = { sf::Vector2f(100.f, 100.f), sf::Vector2f(100.f, 100.f) };
GameEngine::eTexture::type textures[2] = { GameEngine::eTexture::Wall , GameEngine::eTexture::Wall };
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LevelLoader::LevelLoader()
{
CreateObstacle(positions, sizes, textures);
CreateBlobs();
}

void LevelLoader::CreateObstacle(sf::Vector2f *positions, sf::Vector2f *sizes, GameEngine::eTexture::type *textures) {

	ObstacleEntity* obstacle = new ObstacleEntity();

	for (int i = 0; i < 3; i++)
	{
		obstacle->SetSize(sizes[i]);
		obstacle->SetPos(positions[i]);
		obstacle->setTexture(textures[i]);
		GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

	}

}

void LevelLoader::CreateBlobs() {
	BlobEntity* blob = new BlobEntity();
	blob->setVelAngle(10.f);
	blob->setSpeed(10.f);
	blob->SetPos(sf::Vector2f(100.f, 100.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(blob);
}


void LevelLoader::Update()
{
}