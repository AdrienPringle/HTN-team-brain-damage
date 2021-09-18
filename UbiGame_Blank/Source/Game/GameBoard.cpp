#include "GameBoard.h"
#include <SFML/Window/Keyboard.hpp>
#include "GameEngine/GameEngineMain.h"

#include"GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/Util/MenuController.h"
#include "Game/Util/LevelLoader.h"
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
	MenuController::GetInstance()->Update();
    
}

