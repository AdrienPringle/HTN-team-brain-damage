#include "LevelLoader.h"
#include "Game/GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/GameEntities/ObstacleEntity.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include "Game/GameEntities/BlobEntity.h"
#include <iostream>

using namespace Game;

LevelLoader::LevelLoader()
{

	void level1(); {
		////level 1
		sf::Vector2f positions[3] = { sf::Vector2f(500.f, 50.f), sf::Vector2f(50.f, 500.f), sf::Vector2f(500.f, 500.f) };
		sf::Vector2f sizes[3] = { sf::Vector2f(600.f, 100.f), sf::Vector2f(100.f, 600.f),sf::Vector2f(200.f, 100.f) };
		int verticesCount[3] = {4,4,3};

		sf::Vector2f* vertices[] = {nullptr, nullptr, nullptr};
		vertices[0] = new sf::Vector2f[verticesCount[0]]{ sf::Vector2f(0.f, 0.f),sf::Vector2f(0.f, 1000.f),
									 sf::Vector2f(100.f, 1000.f), sf::Vector2f(0.f,100.f) };

		vertices[1] = new sf::Vector2f[verticesCount[1]]{ sf::Vector2f(0.f, 0.f),
									sf::Vector2f(1000.f, 0.f),sf::Vector2f(1000.f, 100.f),
									 sf::Vector2f(0.f, 100.f) };

		vertices[2] = new sf::Vector2f[verticesCount[2]]{ sf::Vector2f(-100.f, 50.f),
								sf::Vector2f(0.f, -50.f), sf::Vector2f(100.f, 50.f) };

		GameEngine::eTexture::type textures[3] = { GameEngine::eTexture::Wall , GameEngine::eTexture::Wall, GameEngine::eTexture::Triangle };

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		CreateObstacle(positions, sizes, textures, vertices, verticesCount);
		CreateBlobs();
	}

}

void LevelLoader::CreateObstacle(sf::Vector2f *positions, sf::Vector2f *sizes,
								GameEngine::eTexture::type *textures, sf::Vector2f **vertices, int *verticesCount) {
	for (int i = 0; i < 3; i++)
	{
		ObstacleEntity* obstacle = new ObstacleEntity();
		obstacle->SetPos(positions[i]);
		obstacle->SetSize(sizes[i]);
		obstacle->setVertices(vertices[i], verticesCount[i]);
		obstacle->setTexture(textures[i]);
		
		GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

	}

}

void LevelLoader::CreateBlobs() {
	BlobEntity* blob = new BlobEntity();
	blob->setVelAngle(10.f);
	blob->setSpeed(80.f);
	blob->SetPos(sf::Vector2f(100.f, 100.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(blob);
}
