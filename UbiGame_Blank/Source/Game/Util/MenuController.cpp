#include "MenuController.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/ButtonComponent.h"
#include "Game/GameBoard.h"
//#include <iostream>


using namespace Game;
MenuController* MenuController::sm_instance = nullptr;


MenuController::MenuController() {
	CreateMenuItems(370.f, 3);
}


void MenuController::CreateMenuItems(float posY, int numitems) {

	const int offset = 200;

/*	for (size_t i = 0; i < numitems; i++)
	{
	*/	item = new GameEngine::Entity();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(item);

		item->SetPos(sf::Vector2f(485.0f, posY));
		item->SetSize(sf::Vector2f(200.0f, 100.0f));

		GameEngine::SpriteRenderComponent* render = item->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent
		buttonComponent = item->AddComponent<GameEngine::ButtonComponent>(); //<-- Use the SpriteRenderComponent
		render->SetTexture(GameEngine::eTexture::Start);
		posY = (posY + offset);
	//}

}

MenuController::~MenuController() {
}

void MenuController::Update() {

	if (item && buttonComponent->isClicked) {
		StartGame();
	}

}

void MenuController::StartGame() {

	//delete menu
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(item);
	item = nullptr;

	//initialize main game
}