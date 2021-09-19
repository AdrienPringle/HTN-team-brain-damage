#include "GameOverEntity.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"


using namespace Game;

const float WIDTH = 20.f;
const float HEIGHT = 20.f;
const float POS_X = 500.f;
const float POS_Y = 500.f;

GameOverEntity::GameOverEntity()
{
    //Render
    m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    m_renderComponent->SetZLevel(3);
    m_renderComponent->SetTexture();

    SetSize(sf::Vector2f(WIDTH, HEIGHT));
    SetPos(sf::Vector2f{POS_X,POS_Y});

    //m_renderButton = AddComponent<Game
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
}
