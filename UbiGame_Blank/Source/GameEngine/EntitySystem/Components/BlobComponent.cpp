#include "BlobComponent.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Entity.h"
#include <random>

#define PI 3.14159265

using namespace GameEngine;

BlobComponent::BlobComponent() {
	render = AddComponent<GameEngine::SpriteRenderComponent>();
	render->SetTexture(GameEngine::eTexture::Tileset);

	auto gen = std::mt19937{ std::random_device{}() };

	auto location = std::uniform_int_distribution<int>{ 50, 450 };
	auto angle = std::uniform_int_distribution<int>{ 0, 359 };

}
BlobComponent::~BlobComponent() {

}

CollidableComponent::CollidableComponent()
{

}


CollidableComponent::~CollidableComponent()
{

}


void CollidableComponent::OnAddToWorld()
{
	Component::OnAddToWorld();
	CollisionManager::GetInstance()->RegisterCollidable(this);

	if (m_useDefaultBox)
		SetupDefaultBoundingBox();
}


void CollidableComponent::OnRemoveFromWorld()
{
	Component::OnRemoveFromWorld();

	CollisionManager::GetInstance()->UnRegisterCollidable(this);
}


void CollidableComponent::SetupDefaultBoundingBox()
{
	//Static AABB for the time being		
	SetBoundingBox(GetEntity()->GetSize());
}


void CollidableComponent::SetBoundingBox(sf::Vector2f size)
{
	m_AABBBox.width = size.x;
	m_AABBBox.height = size.y;

	m_AABBBox.left = -m_AABBBox.width / 2.f;
	m_AABBBox.top = -m_AABBBox.height / 2.f;

	m_useDefaultBox = false;
}

const AABBRect CollidableComponent::GetWorldAABB() const
{
	AABBRect box = m_AABBBox;

	box.left += GetEntity()->GetPos().x;
	box.top += GetEntity()->GetPos().y;

	return box;
}

void BlobComponent::SetAngle(float angle) {
	float x = .1 * cos(angle * PI / 180);
	float y = .1 * sin(angle * PI / 180);

	displacement = { x,y };

}