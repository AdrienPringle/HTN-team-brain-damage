#include "CollidablePhysicsComponent.h"

#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"

#include <vector>
#include <math.h>

#include <iostream>

using namespace GameEngine;

CollidablePhysicsComponent::CollidablePhysicsComponent()
{
	
}


CollidablePhysicsComponent::~CollidablePhysicsComponent()
{

}


void CollidablePhysicsComponent::OnAddToWorld()
{
	CollidableComponent::OnAddToWorld();
}


void CollidablePhysicsComponent::OnRemoveFromWorld()
{
	CollidableComponent::OnRemoveFromWorld();
}


void CollidablePhysicsComponent::Update()
{
	//For the time being just a simple intersection check that moves the entity out of all potential intersect boxes
	std::vector<CollidableComponent*>& collidables = CollisionManager::GetInstance()->GetCollidables();
	
	for (int a = 0; a < collidables.size(); ++a)
	{
		CollidableComponent* colComponent = collidables[a];
		if (colComponent == this)
			continue;
		if (
			GetColliderType() == ColliderType::NoClip || 
			colComponent->GetColliderType() == ColliderType::NoClip
		){
			continue;
		}
		
		
		sf::Vector2f intersect = intersects(colComponent);
		if (abs(intersect.x) > 0 || abs(intersect.y) > 0)
		{
			
			intersect.x /= 2;
			intersect.y /= 2;

			sf::Vector2f pos = GetEntity()->GetPos();
			GetEntity()->SetPos(pos - intersect);
			setIntersectDist(intersect);
			setCollidedComponent(colComponent);
			EntityType type = colComponent->GetEntityType();
			if(type == EntityType::Blob){
				sf::Vector2f colPos = colComponent->GetEntity()->GetPos();
				colComponent->GetEntity()->SetPos(colPos + intersect);
			}
			colComponent->setIntersectDist(-intersect);
			colComponent->setCollidedComponent(this);
			
			
		}
	}
}