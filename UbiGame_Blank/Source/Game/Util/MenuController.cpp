#include "MenuController.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/ButtonComponent.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/GameBoard.h"
#include "Game/Util/LevelLoader.h"
#include "Game/Util/WallManager.h"
#include  "Game/GameEntities/LevelEntity.h"

using namespace Game;
MenuController* MenuController::sm_instance = nullptr;


MenuController::MenuController() {
	CreateMenuItems(570.f, 3);
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
		buttonComponent = item->AddComponent<GameEngine::ButtonComponent>(); //<-- Use the ButtonRender
		render->SetTexture(GameEngine::eTexture::Start);

		item2 = new GameEngine::Entity();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(item2);
		sf::Vector2u windowSize = GameEngine::GameEngineMain::GetInstance()->GetRenderWindow()->getSize();
		item2->SetPos(sf::Vector2f(windowSize.x/2, windowSize.y/2));
		item2->SetSize(sf::Vector2f(windowSize));

		GameEngine::SpriteRenderComponent* render2 = item2->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent
		render2->SetTexture(GameEngine::eTexture::MenuBackground);
		render2->SetZLevel(-1);

		posY = (posY + offset);
	//}

}

MenuController::~MenuController() {
}

void MenuController::Update() {

	if (item && buttonComponent->isClicked) {
		StartGame();		
		startGame = true;
	}
	if (startGame)
	{ 
		WallManager::GetInstance()->Update();				
	}
	
}

void MenuController::StartGame() {

	//delete menu
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(item);
	item = nullptr;

	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(item2);
	item2 = nullptr;

	//initialize main game
	LevelLoader* levelLoader = new LevelLoader();

}