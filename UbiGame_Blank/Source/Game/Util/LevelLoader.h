#pragma once
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
namespace Game
{
	class LevelLoader
	{

	public:
		~LevelLoader();

		LevelLoader();

		void Update();
		
		//void Level1();
		
	private:
		void CreateObstacle(sf::Vector2f *positions, sf::Vector2f *sizes,
							GameEngine::eTexture::type *textures, sf::Vector2f **vertices, int *verticesCount);

		void CreateBlobs();

		bool gameOver;

		GameEngine::Entity* water;
		GameEngine::Entity* island;

		void CreateFrogs();

	};
}
