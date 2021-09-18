#pragma once

#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
    class PlayerMovementComponent : public GameEngine::Component
    {
    public:
        PlayerMovementComponent();
        virtual void Update() override;
        virtual void OnAddToWorld() override;
        int m_lastFaceIndex;
    };
}