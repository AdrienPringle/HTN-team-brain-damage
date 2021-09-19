#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "Game/Util/PointManager.h"

namespace Game
{

    class PointEntity : public GameEngine::Entity
    {
    public:
        PointEntity();
        ~PointEntity();

        virtual void OnAddToWorld() override;
        virtual void OnRemoveFromWorld() override;
        virtual void Update() override;

        

    protected:
        GameEngine::TextRenderComponent *m_renderComponent;
        int points;
        
    };
}
