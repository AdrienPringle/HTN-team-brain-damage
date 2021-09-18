#pragma once
#include "GameEngine/EntitySystem/Component.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	typedef sf::Rect<float> AABBRect;

	class CollidableComponent : public Component
	{
	public:
		CollidableComponent();
		virtual ~CollidableComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		void SetBoundingCircle(float r);
		float getRadius();
		sf::Vector2f  intersects(CollidableComponent* c);

		sf::Vector2f didIntersect();
		void setIntersectDist(sf::Vector2f dist);
		void resolveIntersect();

	protected:
		void SetupDefaultBoundingCircle();
	
		bool	 m_useDefaultCircle;
		float radius;

		sf::Vector2f intersectDist;
	};
}

