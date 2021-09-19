#include "MapEntity.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

#include<iostream>
using namespace Game;

const float WIDTH = 800.f;
const float HEIGHT = 800.f;
float x = GameEngine::GameEngineMain::GetInstance()->GetRenderWindow()->getSize().x / 2;
float y = GameEngine::GameEngineMain::GetInstance()->GetRenderWindow()->getSize().y / 2;


MapEntity::MapEntity()
{
    //Render
    m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    //m_collideComponent = AddComponent<GameEngine::CollidablePhysicsComponent>();
    m_renderComponent->SetTexture(GameEngine::eTexture::Yubel);
    m_renderComponent->SetZLevel(1);

    
    SetPos(sf::Vector2f{ x,y });
    SetSize(sf::Vector2f(WIDTH, HEIGHT));

    border = sf::Rect<float>(0, 0, WIDTH, HEIGHT);
}

MapEntity::~MapEntity()
{

}
void MapEntity::setTexture(GameEngine::eTexture::type texture){
    m_texture = texture;
    m_renderComponent->SetTexture(texture);
}


void MapEntity::OnAddToWorld()
{
    Entity::OnAddToWorld();
}

void MapEntity::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
}

void MapEntity::Update()
{
    Entity::Update();
    //if (m_collideComponent->didIntersect().x != 0 || m_collideComponent->didIntersect().y != 0) {
    //    std::cout << "chicken" << std::endl;
    //}
    SetPos(sf::Vector2f{ x,y });
}
