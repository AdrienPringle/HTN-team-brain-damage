#include "GameOverEntity.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/ButtonComponent.h"
#include "Game/Util/LevelLoader.h"

#include <iostream>
using namespace Game;

const float WIDTH = 500.f;
const float HEIGHT = 500.f;
const float POS_X = 500.f;
const float POS_Y = 500.f;

GameOverEntity::GameOverEntity()
{
    //Render
    m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    m_renderComponent->SetZLevel(3);
    m_renderComponent->SetTexture(GameEngine::eTexture::Circle);
    //m_renderComponent->SetTexture();

    SetSize(sf::Vector2f(WIDTH, HEIGHT));
    SetPos(sf::Vector2f{POS_X,POS_Y});


    GameEngine::Entity* item = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(item);
    m_renderButtonB = item->AddComponent<GameEngine::SpriteRenderComponent>();
    m_renderButton = item->AddComponent<GameEngine::ButtonComponent>();
    m_renderButtonB->SetTexture(GameEngine::eTexture::Restart);
    m_renderButtonB->SetZLevel(15);
    item->SetPos(sf::Vector2f(500.f, 500.f));
    item->SetSize(sf::Vector2f(500.f, 100.f));

    AddChild(item);
}
GameOverEntity::~GameOverEntity()
{
    
}

void GameOverEntity::OnAddToWorld()
{
    Entity::OnAddToWorld();
}

void GameOverEntity::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
}

void GameOverEntity::Update()
{
    Entity::Update();
    if(m_renderButton != nullptr && m_renderButton->isClicked){
        // std::cout<<"click";
        m_renderButtonB->SetZLevel(-15);
    }
}
