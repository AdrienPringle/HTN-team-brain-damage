
#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{			

	class WallEntity : public GameEngine::Entity
	{
	public:
		WallEntity();
		~WallEntity();

		virtual void OnAddToWorld() override;
        virtual void Update() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;		
	};
}