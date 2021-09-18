#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include <SFML/System/Vector2.hpp>



namespace Game
{
	class MovementComponent : public GameEngine::Component
	{
	public:
		MovementComponent();
		virtual ~MovementComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

        void setVel(sf::Vector2f vel);
		void setVelAngle(float a);
        void setSpeed(float s);

		void reflect(sf::Vector2f normal);
		
		float getAngle();
	protected:
		virtual void Update() override;

        float angle;

        sf::Vector2f velocity;
        float speed;
	};
}

