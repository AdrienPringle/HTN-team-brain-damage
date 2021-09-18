#pragma once
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
namespace Game
{
	class LevelLoader
	{

	public:
		~LevelLoader();

		void Update();
	private:


		void CreateObstacle();

		LevelLoader();
		static LevelLoader* sm_istance;

		sf::Vector2f *positions;
		sf::Vector2f *sizes;
		sf::Vector2f **vertices;
		GameEngine::eTexture::type* textures;
		
		int count;

	};
}
