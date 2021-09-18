#include "ObstacleEntity.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"


using namespace Game;

const float WIDTH = 20.f;
const float HEIGHT = 20.f;

ObstacleEntity::ObstacleEntity()
{
    //Render
    m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    m_renderComponent->SetZLevel(2);

    SetSize(sf::Vector2f(WIDTH, HEIGHT));
}

ObstacleEntity::~ObstacleEntity()
{

}
void ObstacleEntity::setTexture(GameEngine::eTexture::type texture){
    m_texture = texture;
    m_renderComponent->SetTexture(texture);
}

void ObstacleEntity::setVertices(sf::Vector2f vertices[], int vertexCount){
    DestroyComponents();
    vertices[0] += GetPos();
    for (int i = 0; i < vertexCount - 1; i++){
        vertices[i+1] += GetPos();
        GameEngine::CollidableComponent* collideComponent = AddComponent<GameEngine::CollidableComponent>();
        collideComponent->SetColliderType(GameEngine::ColliderType::Line);
        collideComponent->setIntersectLine(vertices[i], vertices[i+1]);
    }
    GameEngine::CollidableComponent* collideComponent = AddComponent<GameEngine::CollidableComponent>();
    collideComponent->SetColliderType(GameEngine::ColliderType::Line);
    collideComponent->setIntersectLine(vertices[vertexCount - 1], vertices[0]);

    m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    m_renderComponent->SetZLevel(2);
    m_renderComponent->SetTexture(m_texture);
}

void ObstacleEntity::OnAddToWorld()
{
    Entity::OnAddToWorld();
}

void ObstacleEntity::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
}

void ObstacleEntity::Update()
{
    Entity::Update();
}
