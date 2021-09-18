#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

#include <vector>

namespace Game
{

    class ObstacleEntity : public GameEngine::Entity
    {
    public:
        ObstacleEntity();
        ~ObstacleEntity();

        virtual void OnAddToWorld() override;
        virtual void OnRemoveFromWorld() override;
        virtual void Update() override;

        void setVertices(sf::Vector2f* vertices, int vertexCount);
        void setTexture(GameEngine::eTexture::type texture);

    protected:
        GameEngine::SpriteRenderComponent *m_renderComponent;
        GameEngine::eTexture::type m_texture;
        
    };
}
