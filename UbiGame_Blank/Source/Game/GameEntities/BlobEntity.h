#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

namespace Game
{
    enum BlobState {
        Active, 
        Goal,
        WrongGoal,
        Edge
    };

    class BlobEntity : public GameEngine::Entity
    {
    public:
        BlobEntity();
        ~BlobEntity();

        virtual void OnAddToWorld() override;
        virtual void OnRemoveFromWorld() override;
        virtual void Update() override;

        void setColor(int c);

        void setVelAngle(float a);
        void setSpeed(float s);

        float getAngle();

    protected:
        GameEngine::SpriteRenderComponent *m_renderComponent;
        GameEngine::CollidablePhysicsComponent * m_collideComponent;

        void handleIntersect();
        BlobState state;

        void reflect(sf::Vector2f normal);

        float angle;

        sf::Vector2f velocity;
        float speed;

        int color;
        
    };
}
