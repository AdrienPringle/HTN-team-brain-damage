#include "CollidableComponent.h"

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/Util/CollisionManager.h"

#include <algorithm> 

using namespace GameEngine;

CollidableComponent::CollidableComponent()
	: m_useDefaultCircle(true)
{

}


CollidableComponent::~CollidableComponent()
{

}


void CollidableComponent::OnAddToWorld()
{
	Component::OnAddToWorld();
	CollisionManager::GetInstance()->RegisterCollidable(this);

	if (m_useDefaultCircle)
		SetupDefaultBoundingCircle();
}


void CollidableComponent::OnRemoveFromWorld()
{
	Component::OnRemoveFromWorld();

	CollisionManager::GetInstance()->UnRegisterCollidable(this);
}


void CollidableComponent::SetupDefaultBoundingCircle()
{
	sf::Vector2f size = GetEntity()->GetSize();
	float max = std::max(size.x, size.y) / 2;
	SetBoundingCircle(max);
}


void CollidableComponent::SetBoundingCircle(float r)
{
	radius = r;

	m_useDefaultCircle = false;
}

sf::Vector2f CollidableComponent::intersects(CollidableComponent* c){
	float touchDistance = c->getRadius() + radius;
	sf::Vector2f posDiff = c->GetEntity()->GetPos() - GetEntity()->GetPos();
	
	if(std::abs(posDiff.x) >= touchDistance || std::abs(posDiff.y) >= touchDistance){
		return sf::Vector2f(0.f, 0.f);
	}
	float squareDist = posDiff.x * posDiff.x + posDiff.y * posDiff.y;
	if(squareDist >= touchDistance * touchDistance){
		return sf::Vector2f(0.f, 0.f);
	}

	float dist = sqrt(squareDist);
	float scale = (touchDistance - dist)/dist;
	posDiff.x *= scale;
	posDiff.y *= scale;
	return posDiff;
}

float CollidableComponent::getRadius()
{
	return radius;
}
