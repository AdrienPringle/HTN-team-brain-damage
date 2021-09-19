#include "StartEntity.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

using namespace Game;

const float WIDTH = 20.f;
const float HEIGHT = 20.f;

StartEntity::StartEntity()
{
    SetRotation(0.f);
    //Render
    m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    m_renderComponent->SetTexture(GameEngine::eTexture::Start);
    m_renderComponent->SetZLevel(2);

}

StartEntity::~StartEntity()
{
}

void StartEntity::OnAddToWorld()
{
    Entity::OnAddToWorld();
}

void StartEntity::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
}
