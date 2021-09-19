#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/ButtonComponent.h"

#include <vector>

namespace Game
{

    class GameOverEntity : public GameEngine::Entity
    {
    public:
        GameOverEntity();
        ~GameOverEntity();

        virtual void OnAddToWorld() override;
        virtual void OnRemoveFromWorld() override;
        virtual void Update() override;

    protected:
        GameEngine::SpriteRenderComponent *m_renderComponent;
        GameEngine::ButtonComponent *m_renderButton;
        
    };
}
