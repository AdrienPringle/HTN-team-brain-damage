#include "PlayerMovementComponent.h"

#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs

#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

using namespace Game;

PlayerMovementComponent::PlayerMovementComponent()
    :m_lastFaceIndex(0)
{

}

void PlayerMovementComponent::Update() {
    Component::Update();

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    //By default the displacement is 0,0
    sf::Vector2f displacement{ 0.0f,0.0f };

    //The amount of speed that we will apply when input is received
    const float inputAmount = 100.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        displacement.x -= inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        displacement.x += inputAmount * dt;
    }

    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);

    int maxFaces = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        m_lastFaceIndex++;
        if (m_lastFaceIndex >= maxFaces) {
            m_lastFaceIndex = 0;
        }

        GameEngine::SpriteRenderComponent* spriteRender = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
        if (spriteRender) {
            spriteRender->SetTileIndex(sf::Vector2i(m_lastFaceIndex, 0));
        }


    }
}

void PlayerMovementComponent::OnAddToWorld() {}