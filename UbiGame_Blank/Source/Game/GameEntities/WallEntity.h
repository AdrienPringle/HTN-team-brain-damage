#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"


namespace Game
{

    class WallEntity : public GameEngine::Entity
    {
    public:
        WallEntity();
        ~WallEntity();

        virtual void OnAddToWorld() override;
        virtual void OnRemoveFromWorld() override;
        virtual void Update() override;

        virtual void SetPos(sf::Vector2f pos) override;
        virtual void SetRotation(float rotation) override;

        float getAngle();

    protected:
        GameEngine::SpriteRenderComponent *m_renderComponent;
        GameEngine::CollidableComponent *m_collidableComponent;

        sf::Vector2f getOffset();

        float angle;

        bool isBeingPlaced;
        void place();

        void updateIntersectLine();
        void handleIntersect();
    };
}
