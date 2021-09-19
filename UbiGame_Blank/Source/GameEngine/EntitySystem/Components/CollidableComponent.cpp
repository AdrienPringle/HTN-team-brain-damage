#include "CollidableComponent.h"

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/Util/CollisionManager.h"

#include <algorithm> 

using namespace GameEngine;

CollidableComponent::CollidableComponent()
	: m_useDefaultCircle(true)
{
	intersectDist = sf::Vector2f(0.f, 0.f);
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

void CollidableComponent::setIntersectLine(sf::Vector2f s, sf::Vector2f e){
	start = s;
	end = e;
}

sf::Vector2f CollidableComponent::intersectsCircle(CollidableComponent *c){
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
sf::Vector2f CollidableComponent::intersectsLine(CollidableComponent *c){
	//line to circle
	CollidableComponent* circle;
	CollidableComponent* line;
	if(GetColliderType() == ColliderType::Circle){
		circle = this;
		line = c;
	} else {
		circle = c;
		line = this;
	}
	sf::Vector2f lStart = line->getStart();
	sf::Vector2f lEnd = line->getEnd();

	sf::Vector2f point = circle->GetEntity()->GetPos();

	sf::Vector2f normal = sf::Vector2f(lStart.y - lEnd.y, lEnd.x - lStart.x);
	float multiple = (lEnd.x-lStart.x)*(lStart.y-point.y)-(lStart.x-point.x)*(lEnd.y-lStart.y);
	float dist = (lStart.x-lEnd.x)*(lStart.x-lEnd.x)+(lStart.y-lEnd.y)*(lStart.y-lEnd.y);

	float closestDistance = std::abs(multiple)/sqrt(dist);
	if(closestDistance > circle->getRadius()){
		return sf::Vector2f(0.f, 0.f);
	}

	sf::Vector2f closestPoint = point + sf::Vector2f(normal.x * multiple / dist, normal.y * multiple / dist);

	float len;
	sf::Vector2f diff = lStart - lEnd;
	if(std::abs(diff.x) > std::abs(diff.y)){
		len = (closestPoint.x - lEnd.x)/diff.x;
	}else{
		len = (closestPoint.y - lEnd.y)/diff.y;
	}
	sf::Vector2f offset;
	if(len < 0){
		offset = point - lStart;
		closestDistance = sqrt(offset.x*offset.x + offset.y*offset.y);
	} else if (len > 1) {
		offset = point - lEnd;
		closestDistance = sqrt(offset.x*offset.x + offset.y*offset.y);
	}else{
		offset = point - closestPoint;
	}
	if(closestDistance > circle->getRadius()){
		return sf::Vector2f(0.f, 0.f);
	}

	offset = point - closestPoint; //not the closest distance, but always normal. comment out for closest

	sf::Vector2f change = sf::Vector2f(-offset.x * (circle->getRadius() - closestDistance), -offset.y * (circle->getRadius() - closestDistance));
	return change;
}
sf::Vector2f CollidableComponent::intersects(CollidableComponent* c){
	//no line to line collisions
	if(GetColliderType() == ColliderType::Line && c->GetColliderType() == ColliderType::Line){
		return sf::Vector2f(0.f, 0.f);
	}

	//circle to circle
	if(GetColliderType() == ColliderType::Circle && c->GetColliderType() == ColliderType::Circle){
		return intersectsCircle(c);
	}
	
	return intersectsLine(c);

	
}

float CollidableComponent::getRadius()
{
	return radius;
}
sf::Vector2f CollidableComponent::getStart()
{
	return start;
}
sf::Vector2f CollidableComponent::getEnd()
{
	return end;
}

sf::Vector2f CollidableComponent::didIntersect(){
	return intersectDist;
}
void CollidableComponent::setIntersectDist(sf::Vector2f dist){
	intersectDist = dist;
}
void CollidableComponent::resolveIntersect(){
	intersectDist = sf::Vector2f(0.f, 0.f);
}