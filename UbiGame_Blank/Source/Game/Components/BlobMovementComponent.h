#pragma once

#include "GameEngine/EntitySystem/Component.h"

#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames



namespace Game
{
    class BlobMovementComponent : public GameEngine::Component
    {
    public:
        BlobMovementComponent();
        virtual void Update() override;
        virtual void OnAddToWorld() override;

        void setAngle(float angle);

        sf::Vector2f displacement;
        int m_lastFaceIndex;
    };
}