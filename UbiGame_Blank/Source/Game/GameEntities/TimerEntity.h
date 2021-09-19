#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

namespace Game
{

    class TimerEntity : public GameEngine::Entity
    {
    public:
        TimerEntity();
        ~TimerEntity();

        virtual void OnAddToWorld() override;
        virtual void OnRemoveFromWorld() override;
        virtual void Update() override;

        void setTime(float t);
        bool timeUp();


        void setStartTime(float time);
    protected:
        GameEngine::TextRenderComponent *m_renderComponent;
        float startTime;
        float countdownSeconds;
        
    };
}
