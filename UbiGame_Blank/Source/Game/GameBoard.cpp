#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"


using namespace Game;

GameBoard::GameBoard()
{

}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	GameEngine::Entity* m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	m_player->SetPos(sf::Vector2f(50.0f, 50.0f));
	m_player->SetSize(sf::Vector2f(200.0f, 200.0f));

	//Render
	GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>();

	//render->SetFillColor(sf::Color::Red);
	render->SetTexture(GameEngine::eTexture::Meme);// <-- Assign the texture to this entity

	//Movement
}