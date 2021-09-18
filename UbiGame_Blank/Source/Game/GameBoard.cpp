#include "GameBoard.h"
#include <SFML/Window/Keyboard.hpp>
#include "GameEngine/GameEngineMain.h"
<<<<<<< HEAD
#include"GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/Util/MenuController.h"
=======

#include "Game/Util/WallManager.h"
>>>>>>> 4fda33bf34b1cd2ca031a95e9e2c3e32668ac846

using namespace Game;

GameBoard::GameBoard()
{

}



GameBoard::~GameBoard()
{

}


void GameBoard::Update()
<<<<<<< HEAD
{	
	MenuController::GetInstance()->Update();
=======
{
    WallManager::GetInstance()->Update();
>>>>>>> 4fda33bf34b1cd2ca031a95e9e2c3e32668ac846
}