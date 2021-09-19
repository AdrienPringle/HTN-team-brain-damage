#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"


#include <vector>

namespace Game
{

    class GoalEntity : public GameEngine::Entity
    {
    public:
        GoalEntity();
        ~GoalEntity();

        void setColor(int c);

        virtual void Update() override;
        virtual void SetPos(sf::Vector2f) override;

    protected:
        GameEngine::SpriteRenderComponent *m_renderComponent;
        GameEngine::CollidableComponent * m_collidableComponent;
        
        bool isMonch;
        float monchTime;

        sf::Vector2f initialPos;
        
    };
}
