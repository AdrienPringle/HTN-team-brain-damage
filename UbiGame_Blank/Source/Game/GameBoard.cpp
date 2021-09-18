#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"

#include "Game/Components/PlayerMovementComponent.h"

#include "Game/Components/BlobMovementComponent.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

#include <iostream>;
#include <random>
#include<math.h>
#define PI 3.14159265

using namespace Game;

GameBoard::GameBoard()
{	
	auto gen = std::mt19937{ std::random_device{}() };

	auto location = std::uniform_int_distribution<int>{ 50, 450 };
	auto angle = std::uniform_int_distribution<int>{ 0, 359};

	CreatePlayer();
	for (int i = 0; i <= 100; i++) {
		CreateBlob(location(gen), location(gen), angle(gen));
	}
}


GameBoard::~GameBoard()
{	

}


void GameBoard::Update()
{	
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	m_player->SetPos(sf::Vector2f(100.0f, 100.0f));
	m_player->SetSize(sf::Vector2f(200.0f, 200.0f));

	//Render
	GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>();

	//render->SetFillColor(sf::Color::Red);
	render->SetTexture(GameEngine::eTexture::Meme);// <-- Assign the texture to this entity

	//Movement
	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player

	std::cout << render->GetEntity()->GetPos().x << std::endl;
}

void GameBoard::CreateBlob(float x, float y, float angle)
{
	m_blob = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_blob);

	m_blob->SetPos(sf::Vector2f(x, y));
	m_blob->SetSize(sf::Vector2f(10.0f, 10.0f));
	GameEngine::SpriteRenderComponent* render = m_blob->AddComponent<GameEngine::SpriteRenderComponent>();
	
	render->SetTexture(GameEngine::eTexture::Tileset);
	Game::BlobMovementComponent* blobMove = m_blob->AddComponent<Game::BlobMovementComponent>();
	GameEngine::CollidablePhysicsComponent* blobCollide = m_blob->AddComponent<GameEngine::CollidablePhysicsComponent>();
	blobMove->setAngle(angle);
	
}