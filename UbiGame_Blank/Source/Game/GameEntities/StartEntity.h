#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

namespace Game {
    class StartEntity : public GameEngine::Entity
    {

public:
    StartEntity();
    ~StartEntity();

    virtual void OnAddToWorld() override;
    virtual void OnRemoveFromWorld() override;
    //virtual void Update() override;


protected:
    GameEngine::SpriteRenderComponent* m_renderComponent;

        };
    
}
 


