#pragma once
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
namespace Game
{
	class LevelLoader
	{

	public:
		~LevelLoader();

		void Update();

		LevelLoader();
		
		
	private:
		void CreateObstacle(sf::Vector2f *positions, sf::Vector2f *sizes, GameEngine::eTexture::type *textures);

		void CreateBlobs();

		sf::Vector2f *positions;
		sf::Vector2f *sizes;
		sf::Vector2f **vertices;
		GameEngine::eTexture::type* textures;
		
		int count;

	};
}
