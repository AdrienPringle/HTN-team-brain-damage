#pragma once
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Entity.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace GameEngine
{
	typedef sf::Rect<float> AABBRect;

	class BlobComponent : public GameEngine::Entity
	{
	public:
		BlobComponent();
		virtual ~BlobComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		void SetAngle(float angle);
	protected:
		GameEngine::SpriteRenderComponent* render;
	};
}