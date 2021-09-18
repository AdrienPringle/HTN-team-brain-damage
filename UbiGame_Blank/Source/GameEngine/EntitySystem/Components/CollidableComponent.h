#pragma once
#include "GameEngine/EntitySystem/Component.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	typedef sf::Rect<float> AABBRect;

	enum ColliderType {
		Circle,
		Line,
		NoClip
	};

	class CollidableComponent : public Component
	{
	public:
		CollidableComponent();
		virtual ~CollidableComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		
		sf::Vector2f  intersects(CollidableComponent* c);

		sf::Vector2f didIntersect();
		void setIntersectDist(sf::Vector2f dist);
		void resolveIntersect();

		void SetColliderType(ColliderType type){ m_type = type; }
		ColliderType GetColliderType(){ return m_type; }

		//for circle
		float getRadius();
		void SetBoundingCircle(float r);

		//for line
		float getLength();
		sf::Vector2f getStart();
		sf::Vector2f getEnd();
		void setIntersectLine(sf::Vector2f s, sf::Vector2f e);
		


	protected:
		void SetupDefaultBoundingCircle();

		sf::Vector2f intersectsCircle(CollidableComponent* c);
		sf::Vector2f intersectsLine(CollidableComponent * c);
	
		bool	 m_useDefaultCircle;

		float radius;
		sf::Vector2f start;
		sf::Vector2f end; 

		sf::Vector2f intersectDist;

		ColliderType m_type;
	};
}

