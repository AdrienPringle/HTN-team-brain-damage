#pragma once

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/ButtonComponent.h"
#include "Game/GameEntities/TimerEntity.h"
#include "Game/GameEntities/GameOverEntity.h"



namespace Game
{	
	enum GameState {
		MenuScreen,
		Game,
		TimeUp
	};
	class MenuController:public GameEngine::Entity
	{
	public:
		~MenuController();
		static MenuController* GetInstance() { if (!sm_instance) sm_instance = new MenuController(); return sm_instance; }

		void Update();
	

		void StartGame();

	private:
		MenuController();
		static MenuController* sm_instance;

		void CreateMenuItems(float posY, int numItems);          // <-- Added Function

		GameEngine::ButtonComponent* buttonComponent;

		// bool startGame = false;
		GameState gameState;

		GameEngine::Entity* item;
		GameEngine::Entity* item2;

		Game::TimerEntity* timer;

		Game::GameOverEntity* endScreen;


	};
}