#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"

#include "Game/Util/WallManager.h"

using namespace Game;

GameBoard::GameBoard()
{

}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{
    WallManager::GetInstance()->Update();
}