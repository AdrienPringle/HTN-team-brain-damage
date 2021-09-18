#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			Player = 0,
			Tileset,
			BG,
			Particles,
<<<<<<< HEAD
			Start,
=======
			Wall,
			Circle,
			Cliff,
			Triangle,
>>>>>>> 4fda33bf34b1cd2ca031a95e9e2c3e32668ac846
			Count,
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::Player:    return "player.png";
		case eTexture::Tileset:   return "tileset.png";
		case eTexture::BG:		  return "bg.png";
		case eTexture::Particles: return "particles.png";
<<<<<<< HEAD
		case eTexture::Start: return "start.png";

=======
		case eTexture::Wall: 	  return "wall.png";
		case eTexture::Circle: 	  return "circle.png";
		case eTexture::Cliff: 	  return "cliff.png";
		case eTexture::Triangle:  return "triangle.png";
>>>>>>> 4fda33bf34b1cd2ca031a95e9e2c3e32668ac846
		default:       return "UnknownTexType";
		}
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture);
}

