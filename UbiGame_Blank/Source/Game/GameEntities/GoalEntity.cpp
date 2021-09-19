#include "GoalEntity.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"


using namespace Game;

const float WIDTH = 200.f;
const float HEIGHT = 200.f;

GoalEntity::GoalEntity()
{
    //Render
    m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    m_renderComponent->SetZLevel(1);


    m_collidableComponent = AddComponent<GameEngine::CollidableComponent>();
    m_collidableComponent->SetColliderType(GameEngine::ColliderType::Circle);
    m_collidableComponent->SetEntityType(GameEngine::EntityType::Goal);

    SetSize(sf::Vector2f(WIDTH, HEIGHT));
}

void GoalEntity::setColor(int c){
    m_renderComponent->SetTexture(GameEngine::goalTextures[c-1]);
    m_collidableComponent->setColor(c);
}

GoalEntity::~GoalEntity()
{

}