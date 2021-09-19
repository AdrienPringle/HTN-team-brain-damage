#include "PointEntity.h"


#include "GameEngine/GameEngineMain.h"
#include "SFML/Graphics/Color.hpp"

#include <iostream>

int previous=0;
using namespace Game;

PointEntity::PointEntity()
{
    m_renderComponent = AddComponent<GameEngine::TextRenderComponent>();
    m_renderComponent->SetFont("comici.ttf");
    m_renderComponent->SetCharacterSizePixels(30);
    m_renderComponent->SetColor(sf::Color(255,255,255));
	m_renderComponent->SetString("Points: 0");
	m_renderComponent->SetZLevel(10);
    SetPos(sf::Vector2f{450.f,950.f});
}

PointEntity::~PointEntity()
{
}

void PointEntity::OnAddToWorld()
{
    Entity::OnAddToWorld();
}

void PointEntity::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
}


void PointEntity::Update()
{
    Entity::Update();

    // if(PointManager::GetInstance()->GetGoalBlobs() != previous){
    //     points = previous = PointManager::GetInstance()->GetGoalBlobs();
    // }
    // std::cout << PointManager::GetInstance()->GetGoalBlobs() << "\t";
    // m_renderComponent->SetString("Points: " + std::to_string(points));

    m_renderComponent->SetString("Points: " + std::to_string(PointManager::GetInstance()->GetGoalBlobs()));
    // m_renderComponent->
}

