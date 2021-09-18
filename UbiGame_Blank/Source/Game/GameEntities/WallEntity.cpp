#include "WallEntity.h"

#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

using namespace Game;

const float WIDTH = 200.f;
const float HEIGHT = 20.f;

WallEntity::WallEntity()
{
    isBeingPlaced = true;
    SetRotation(0.f);
    //Render
    m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    m_renderComponent->SetTexture(GameEngine::eTexture::Wall);
    m_renderComponent->SetZLevel(2);

    SetSize(sf::Vector2f(WIDTH, HEIGHT));
}

WallEntity::~WallEntity()
{
}

void WallEntity::OnAddToWorld()
{
    Entity::OnAddToWorld();
}

void WallEntity::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
}

void WallEntity::Update()
{
    Entity::Update();
    float dt = GameEngine::GameEngineMain::GetTimeDelta();

    if (isBeingPlaced)
    {
        //set rotation based on mouse position
        sf::RenderWindow *window = GameEngine::GameEngineMain::GetInstance()->GetRenderWindow();
        sf::Vector2f diff = GetPos() - getOffset() - sf::Vector2f(sf::Mouse::getPosition(*window));
        float angle = atan2(-diff.y, -diff.x) * 180 / M_PI;
        SetRotation(angle);

        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            isBeingPlaced = false;
        }
    }
}

sf::Vector2f WallEntity::getOffset()
{
    return sf::Vector2f(
        WIDTH / 2 * cos(GetRot() * M_PI / 180.f),
        WIDTH / 2 * sin(GetRot() * M_PI / 180.f));
}

void WallEntity::SetPos(sf::Vector2f pos)
{
    Entity::SetPos(pos + getOffset());
}

void WallEntity::SetRotation(float rotation)
{
    m_pos -= getOffset();
    Entity::SetRotation(rotation);
    m_pos += getOffset();
}

void WallEntity::place()
{
    isBeingPlaced = false;
}

float WallEntity::getAngle()
{
    return angle;
}