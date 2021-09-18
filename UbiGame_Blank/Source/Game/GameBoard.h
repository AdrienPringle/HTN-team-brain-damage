#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include <string>

#include <vector>

namespace Game
{
<<<<<<< HEAD
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
=======
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application
>>>>>>> 4fda33bf34b1cd2ca031a95e9e2c3e32668ac846
	class PlayerEntity;

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		void Update();
		bool IsGameOver() { return false; }
<<<<<<< HEAD
=======

	private:
	};
}
>>>>>>> 4fda33bf34b1cd2ca031a95e9e2c3e32668ac846

	private:

	};
}