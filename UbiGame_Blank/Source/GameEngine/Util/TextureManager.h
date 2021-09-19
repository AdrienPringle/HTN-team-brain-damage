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
			Start,
			Wall,
			Circle,
			Cliff,
			Triangle,
			Yubel,
			MenuBackground,
			Water,
			Island,
			Blob1,
			Blob2,
			Blob3,
			Blob4,
			Goal1,
			Goal2,
			Goal3,
			Goal4,
			Count,
		};	
	}	
	const eTexture::type blobTextures[4] = {eTexture::type::Blob1, eTexture::type::Blob2, eTexture::type::Blob3, eTexture::type::Blob4};
	const eTexture::type goalTextures[4] = {eTexture::type::Goal1, eTexture::type::Goal2, eTexture::type::Goal3, eTexture::type::Goal4};

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::Player:    return "player.png";
		case eTexture::Tileset:   return "tileset.png";
		case eTexture::BG:		  return "bg.png";
		case eTexture::Particles: return "particles.png";
		case eTexture::Start: return "start.png";
		case eTexture::Wall: 	  return "wall.png";
		case eTexture::Circle: 	  return "circle.png";
		case eTexture::Cliff: 	  return "cliff.png";
		case eTexture::Triangle:  return "triangle.png";
		case eTexture::Yubel:	  return "yubel.jpg";
		case eTexture::MenuBackground:	  return "MenuBackground.png";
		case eTexture::Water:	  return "Water.png";
		case eTexture::Island:	  return "Island.png";

		case eTexture::Blob1: 	  return "blob1.png";
		case eTexture::Blob2: 	  return "blob2.png";
		case eTexture::Blob3: 	  return "blob3.png";
		case eTexture::Blob4:     return "blob4.png";

		case eTexture::Goal1: 	  return "goal1.png";
		case eTexture::Goal2: 	  return "goal2.png";
		case eTexture::Goal3: 	  return "goal3.png";
		case eTexture::Goal4:     return "goal4.png";
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

