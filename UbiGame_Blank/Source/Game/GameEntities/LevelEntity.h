#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "BlobEntity.h"
#include "GameEngine/Util/CollisionManager.h"
#include <vector>

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
        void setTime(int m);

    protected:
        GameEngine::SpriteRenderComponent *m_renderComponent;

        float frequency;
        float amount;
        bool finishedSpawning;
        int counter;
        bool spawn;
        int minute;
        
    };
}
