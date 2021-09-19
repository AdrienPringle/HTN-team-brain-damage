#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Game/Util/MenuController.h"
#include "Game/Util/WallManager.h"
#include "Game/Util/PointManager.h"

#include<iostream>

using namespace Game;

GameBoard::GameBoard()
{
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{
    MenuController::GetInstance()->Update();
}