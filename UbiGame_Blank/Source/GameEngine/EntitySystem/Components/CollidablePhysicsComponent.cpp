#include "CollidablePhysicsComponent.h"

#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"

#include <vector>
#include <math.h>

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
		
		sf::Vector2f intersect = intersects(colComponent);
		if (intersect.x > 0 || intersect.y > 0)
		{
			intersect.x /= 2;
			intersect.y /= 2;

			sf::Vector2f pos = GetEntity()->GetPos();
			GetEntity()->SetPos(pos - intersect);

			sf::Vector2f colPos = colComponent->GetEntity()->GetPos();
			colComponent->GetEntity()->SetPos(colPos + intersect);
		}
	}
}