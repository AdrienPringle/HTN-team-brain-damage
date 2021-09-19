#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"

#include "Game/Util/WallManager.h"
#include "Game/Util/PointManager.h"

#include "Game/GameEntities/GoalEntity.h"
#include "Game/GameEntities/BlobEntity.h"
#include "Game/GameEntities/LevelEntity.h"

#include<iostream>

using namespace Game;
int pointsholder = 0;
int pointsholder2 = 0;
int pointsholder3 = 0;

GameBoard::GameBoard()
{

    GoalEntity* goal1 = new GoalEntity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(goal1);
    goal1->SetPos(sf::Vector2f(100.f, 100.f));
    goal1->setColor(4); //1-4
    GoalEntity* goal2 = new GoalEntity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(goal2);
    goal2->SetPos(sf::Vector2f(900.f, 100.f));
    goal2->setColor(3); //1-4
    GoalEntity* goal3 = new GoalEntity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(goal3);
    goal3->SetPos(sf::Vector2f(100.f, 900.f));
    goal3->setColor(2); //1-4
    GoalEntity* goal4 = new GoalEntity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(goal4);
    goal4->SetPos(sf::Vector2f(900.f, 900.f));
    goal4->setColor(1); //1-4


    BlobEntity* blob = new BlobEntity();
    blob->setVelAngle(45);
    blob->setSpeed(45);
    blob->SetPos(sf::Vector2f{300.f,300.f});
    blob->setColor(1); //1-4
    GameEngine::GameEngineMain::GetInstance()->AddEntity(blob);

    BlobEntity* blob2 = new BlobEntity();
    blob2->setVelAngle(120);
    blob2->setSpeed(30);
    blob2->SetPos(sf::Vector2f{ 250.f,250.f });
    blob2->setColor(3); //1-4
    GameEngine::GameEngineMain::GetInstance()->AddEntity(blob2);

    BlobEntity* blob3 = new BlobEntity();
    blob3->setVelAngle(300);
    blob3->setSpeed(20);
    blob3->SetPos(sf::Vector2f{ 150.f,550.f });
    blob3->setColor(2); //1-4
    GameEngine::GameEngineMain::GetInstance()->AddEntity(blob3);
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{
    WallManager::GetInstance()->Update();
    if (PointManager::GetInstance()->GetGoalBlobs() > pointsholder) {
        std::cout << "Goals:" << PointManager::GetInstance()->GetGoalBlobs() << std::endl;
        pointsholder++;
    }

    if (PointManager::GetInstance()->GetSuicidalBlobs() > pointsholder2) {
        std::cout << "Dead Bois:" << PointManager::GetInstance()->GetSuicidalBlobs() << std::endl;
        pointsholder2++;
    }
    if (PointManager::GetInstance()->GetWrongGoalBlobs() > pointsholder3) {
        std::cout << "Dead Bois:" << PointManager::GetInstance()->GetWrongGoalBlobs() << std::endl;
        pointsholder2++;
    }
    
}