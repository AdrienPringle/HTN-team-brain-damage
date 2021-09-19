#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"


#include <vector>

namespace Game
{   
    enum GoalState {
        Idle, 
        Monch,
        Anger
    };

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
        
        GoalState state;
        float monchTime;

        int color;

        sf::Vector2f initialPos;
        
    };
}
