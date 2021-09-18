#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"

#include "Game/GameEntities/WallEntity.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"



#include <iostream>



using namespace Game;

GameBoard::GameBoard()
{

    
    renderWall();
    std::cout << GameEngine::GameEngineMain::GetInstance()->GetRenderWindow()->getSize().x;


    //delet
    GameEngine::Entity*player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player);

	player->SetPos(sf::Vector2f(50.f, 50.f));
	player->SetSize(sf::Vector2f(100.f, 100.f));
    GameEngine::SpriteRenderComponent* renderComponent = player->AddComponent<GameEngine::SpriteRenderComponent>();	
	renderComponent->SetTexture(GameEngine::eTexture::Temp);
	renderComponent->SetZLevel(2);



}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

void GameBoard::renderWall(){
    WallEntity* wall = new WallEntity();

    GameEngine::GameEngineMain::GetInstance()->AddEntity(wall);
    wall->SetPos(sf::Vector2f(50.f, 50.f)); 
}