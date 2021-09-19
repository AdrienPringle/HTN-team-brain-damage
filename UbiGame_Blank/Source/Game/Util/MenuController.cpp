#include "MenuController.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/ButtonComponent.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/GameBoard.h"
#include "Game/Util/LevelLoader.h"
#include "Game/Util/WallManager.h"
#include "Game/Util/PointManager.h"
#include  "Game/GameEntities/LevelEntity.h"
#include "Game/GameEntities/GameOverEntity.h"
#include "Game/GameEntities/TimerEntity.h"


#include <iostream>

using namespace Game;
MenuController* MenuController::sm_instance = nullptr;


MenuController::MenuController() {
	CreateMenuItems(800.f, 3);

	timer = new TimerEntity();
	timer->setTime(1.01);
	timer->setStartTime(GameEngine::GameEngineMain::GetInstance()->GetGameTime());
	GameEngine::GameEngineMain::GetInstance()->AddEntity(timer);
	PointManager::GetInstance()->ResetGoal();

	gameState = GameState::MenuScreen;
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

		endScreen = nullptr;
	//}

}

MenuController::~MenuController() {
}

void MenuController::Update() {
	switch (gameState) {
		case GameState::MenuScreen:{
			if (item && buttonComponent->isClicked) {
				StartGame();		
				// startGame = true;
				gameState = GameState::Game;
				timer->setStartTime(GameEngine::GameEngineMain::GetInstance()->GetGameTime());
			}
			break;
		}
		case GameState::Game:{
			WallManager::GetInstance()->Update();
			if (timer->timeUp()) {
				gameState = GameState::TimeUp;

				
				endScreen = new Game::GameOverEntity();
				GameEngine::GameEngineMain::GetInstance()->AddEntity(endScreen);
				PointManager::GetInstance()->ResetGoal();

			}	
			break;
		}
		case GameState::TimeUp:{
			if(endScreen->m_renderButton->isClicked){
				GameEngine::GameEngineMain::GetInstance()->RemoveEntity(endScreen);
				gameState = GameState::Game;
				timer->setStartTime(GameEngine::GameEngineMain::GetInstance()->GetGameTime());
				PointManager::GetInstance()->ResetGoal();

			}
			break;
		}
	}
	
	// if(GameEngine::GameEngineMain::GetInstance()->GetGameTime() >= 2.f){
	// 	GameOverEntity* gameOver = new GameOverEntity;
	// 	GameEngine::GameEngineMain::GetInstance()->AddEntity(gameOver);
	// }
	
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