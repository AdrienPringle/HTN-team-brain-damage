#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

#include <SFML/Graphics/Rect.hpp>
#include <vector>

namespace Game
{

    class MapEntity : public GameEngine::Entity
    {
    public:
        MapEntity();
        ~MapEntity();

        virtual void OnAddToWorld() override;
        virtual void OnRemoveFromWorld() override;
        virtual void Update() override;

        void setVertices(sf::Vector2f* vertices, int vertexCount);
        void setTexture(GameEngine::eTexture::type texture);

    protected:
        GameEngine::SpriteRenderComponent *m_renderComponent;
        GameEngine::CollidablePhysicsComponent* m_collideComponent;
        GameEngine::eTexture::type m_texture;
        sf::Rect<float> border;
        
        
    };
}
