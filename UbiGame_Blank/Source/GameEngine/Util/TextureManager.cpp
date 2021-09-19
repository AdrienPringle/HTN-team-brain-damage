#include "TextureManager.h"

using namespace GameEngine;

TextureManager* TextureManager::sm_instance = nullptr;

TextureManager::TextureManager()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		m_textures[a] = nullptr;
	}
}


TextureManager::~TextureManager()
{
	UnLoadTextures();
}


void TextureManager::LoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		sf::Texture* texture = new sf::Texture();
		std::string filePath;
		filePath.append("Resources/img/");
		filePath.append(GetPath((eTexture::type)a));
		texture->loadFromFile(filePath);

		m_textures[a] = texture;
	}
}


void TextureManager::UnLoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		delete m_textures[a];
		m_textures[a] = nullptr;
	}
}

namespace TextureHelper
{
    sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
    {
        switch (texture)
        {
        case  GameEngine::eTexture::Start: return sf::Vector2f(200.f, 100.f);
        case GameEngine::eTexture::Wall:  	 return sf::Vector2f(196.f, 28.f);
		case GameEngine::eTexture::Circle:   return sf::Vector2f(896.f, 896.f);
		case GameEngine::eTexture::Cliff:   return sf::Vector2f(200.f, 200.f);
		case GameEngine::eTexture::Triangle:   return sf::Vector2f(1845.f, 1492.f);
		case GameEngine::eTexture::Yubel:   return sf::Vector2f(225.f, 225.f);
		case GameEngine::eTexture::MenuBackground:   return sf::Vector2f(1000.f, 1000.f);
		case GameEngine::eTexture::Water:   return sf::Vector2f(1000.f, 1000.f);
		case GameEngine::eTexture::Island:   return sf::Vector2f(9072.f, 8521.f);
        case GameEngine::eTexture::Player:  return sf::Vector2f(32.f, 32.f);
        case GameEngine::eTexture::Tileset: return sf::Vector2f(32.f, 32.f);
        case GameEngine::eTexture::BG:	     return sf::Vector2f(500.f, 500.f);
        case GameEngine::eTexture::Particles: return sf::Vector2f(31.f, 32.f);
        case GameEngine::eTexture::Wall:  	 return sf::Vector2f(1000.f, 160.f);
		case GameEngine::eTexture::Blob1:   return sf::Vector2f(900.f, 800.f);
		case GameEngine::eTexture::Blob2:   return sf::Vector2f(900.f, 800.f);
		case GameEngine::eTexture::Blob3:   return sf::Vector2f(900.f, 800.f);
		case GameEngine::eTexture::Blob4:   return sf::Vector2f(900.f, 800.f);
		case GameEngine::eTexture::Goal1:   return sf::Vector2f(896.f, 896.f);
		case GameEngine::eTexture::Goal2:   return sf::Vector2f(896.f, 896.f);
		case GameEngine::eTexture::Goal3:   return sf::Vector2f(896.f, 896.f);
		case GameEngine::eTexture::Goal4:   return sf::Vector2f(896.f, 896.f);

		default:							 return sf::Vector2f(-1.f, -1.f);
        }
    }
}
