#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Game/Util/MenuController.h"
#include "Game/Util/WallManager.h"
#include "Game/Util/PointManager.h"
#include "Game/GameEntities/TimerEntity.h"
#include "Game/GameEntities/LevelEntity.h"

#include<iostream>

using namespace Game;

GameBoard::GameBoard()
{
    TimerEntity* timer = new TimerEntity();
    timer->setTime(1);
    GameEngine::GameEngineMain::GetInstance()->AddEntity(timer);

    

    LevelEntity* level = new LevelEntity();
    level->setTime(1);
    level->setFrenquency(5);
    GameEngine::GameEngineMain::GetInstance()->AddEntity(level);
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{
    MenuController::GetInstance()->Update();
}