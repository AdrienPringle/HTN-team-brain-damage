#pragma once

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/ButtonComponent.h"

namespace Game
{
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

		bool startGame = false;

		GameEngine::Entity* item;
		GameEngine::Entity* item2;


	};
}