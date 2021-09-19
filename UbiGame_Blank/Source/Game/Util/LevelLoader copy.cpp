#include "LevelLoader.h"
#include "Game/GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/GameEntities/ObstacleEntity.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include "Game/GameEntities/BlobEntity.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/GameEntities/BlobEntity.h"
#include "Game/GameEntities/LevelEntity.h"
#include"Game/GameEntities/GoalEntity.h"
#include <iostream>

using namespace Game;
LevelLoader::LevelLoader()
{
	sf::Vector2u windowSize = GameEngine::GameEngineMain::GetInstance()->GetRenderWindow()->getSize();

	//Render
	water = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(water);

	water->SetPos(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));
	water->SetSize(sf::Vector2f(windowSize));

	GameEngine::SpriteRenderComponent* render = water->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent
	render->SetTexture(GameEngine::eTexture::Water);

	island = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(island);
	island->SetPos(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));
	island->SetSize(sf::Vector2f(windowSize));

	GameEngine::SpriteRenderComponent* render2 = island->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent
	render2->SetTexture(GameEngine::eTexture::Island);
	render2->SetZLevel(0);


	void level1(); {
		gameOver = false;

		////level 1
		sf::Vector2f positions[5] = { sf::Vector2f(500.f, 50.f), sf::Vector2f(50.f, 500.f), 
									sf::Vector2f(500.f, 950.f), sf::Vector2f(950.f, 500.f), sf::Vector2f(500.f, 500.f), };

		sf::Vector2f sizes[5] = { sf::Vector2f(300.f, 100.f), sf::Vector2f(300.f, 100.f),
									sf::Vector2f(300.f, 100.f), sf::Vector2f(300.f, 100.f), sf::Vector2f(200.f, 100.f) };
		int verticesCount[5] = {4,4,4,4,3};

		sf::Vector2f* vertices[] = {nullptr, nullptr, nullptr, nullptr, nullptr};
		vertices[0] = new sf::Vector2f[verticesCount[0]]{ sf::Vector2f(-150.f, 50.f),sf::Vector2f(-150.f, -50.f),
									 sf::Vector2f(150.f, -50.f), sf::Vector2f(150.f,50.f) };

		vertices[1] = new sf::Vector2f[verticesCount[1]]{ sf::Vector2f(-50.f, 300.f),
									sf::Vector2f(-50.f, -150.f),sf::Vector2f(50.f, -150.f),
									 sf::Vector2f(50.f, 150.f) };

		vertices[2] = new sf::Vector2f[verticesCount[0]]{ sf::Vector2f(-150.f, 50.f),sf::Vector2f(-150.f, -50.f),
							 sf::Vector2f(150.f, -50.f), sf::Vector2f(150.f,50.f) };

		vertices[3] = new sf::Vector2f[verticesCount[1]]{ sf::Vector2f(-50.f, 150.f),
									sf::Vector2f(-50.f, -150.f),sf::Vector2f(50.f, -150.f),
									 sf::Vector2f(50.f, 150.f) };

		vertices[4] = new sf::Vector2f[verticesCount[2]]{ sf::Vector2f(-100.f, 50.f),
						sf::Vector2f(0.f, -50.f), sf::Vector2f(100.f, 50.f) };

		GameEngine::eTexture::type textures[5] = { GameEngine::eTexture::Wall , GameEngine::eTexture::Wall, GameEngine::eTexture::Wall,
													GameEngine::eTexture::Wall , GameEngine::eTexture::Triangle };

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		CreateObstacle(positions, sizes, textures, vertices, verticesCount);
		CreateBlobs();
		CreateFrogs();
	}

}

void LevelLoader::CreateObstacle(sf::Vector2f *positions, sf::Vector2f *sizes,
								GameEngine::eTexture::type *textures, sf::Vector2f **vertices, int *verticesCount) {
	float rotation=0.f;
	for (int i = 0; i < 5; i++)
	{


		ObstacleEntity* obstacle = new ObstacleEntity();
		obstacle->SetPos(positions[i]);
		obstacle->SetSize(sizes[i]);
		obstacle->setVertices(vertices[i], verticesCount[i]);
		obstacle->setTexture(textures[i]);
		obstacle->SetRotation(rotation);
	
		
		GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);
		rotation += (90.f);
	}

}

void LevelLoader::CreateBlobs() {
	//BlobEntity* blob = new BlobEntity();
	//blob->setVelAngle(10.f);
	//blob->setSpeed(80.f);
	//blob->SetPos(sf::Vector2f(100.f, 100.f));
	//GameEngine::GameEngineMain::GetInstance()->AddEntity(blob);

	LevelEntity* level = new LevelEntity();
	level->setTime(2);
	level->setFrenquency(3);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(level);
}

void LevelLoader::CreateFrogs() {

	GoalEntity* goal = new GoalEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(goal);
	goal->SetPos(sf::Vector2f(150.f, 150.f));
	goal->setColor(1); //1-4	
	goal->SetRotation(-10.f);


	GoalEntity* goal2 = new GoalEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(goal2);
	goal2->SetPos(sf::Vector2f(150.f, 850.f));
	goal2->setColor(2); //1-4
	goal2->SetRotation(-10.f);

	GoalEntity* goal3 = new GoalEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(goal3);
	goal3->SetPos(sf::Vector2f(850.f, 850.f));
	goal3->setColor(3); //1-4
	goal3->SetRotation(10.f);

	GoalEntity* goal4 = new GoalEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(goal4);
	goal4->SetPos(sf::Vector2f(850.f, 150.f));
	goal4->setColor(4); //1-4
	goal4->SetRotation(10.f);
}


void LevelLoader::Update() {
	//if (timer=0 && gameover = false)
	//set gameover = true 
	//menucomponent menucomponent = new menucomponent();

}