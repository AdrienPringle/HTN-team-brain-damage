#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

namespace Game
{

    class LevelEntity : public GameEngine::Entity
    {
    public:
        LevelEntity();
        ~LevelEntity();

        virtual void OnAddToWorld() override;
        virtual void OnRemoveFromWorld() override;
        virtual void Update() override;

        void setFrenquency(float f);
        void setAmount(float a);
        void setLevel(int l);

    protected:
        GameEngine::SpriteRenderComponent *m_renderComponent;

        float frequency;
        float amount;
        bool finishedSpawning;
        float counter;
        bool spawn;
        
    };
}
