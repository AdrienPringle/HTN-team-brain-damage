
#include "WallEntity.h"

#include "GameEngine/GameEngineMain.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"


using namespace Game;


WallEntity::WallEntity(){

    //Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();	
	m_renderComponent->SetTexture(GameEngine::eTexture::Player);
	m_renderComponent->SetZLevel(2);

    SetSize(sf::Vector2f(200.f, 20.f));

}
WallEntity::~WallEntity(){

}

void WallEntity::OnAddToWorld(){
    Entity::OnAddToWorld();



}
void WallEntity::Update(){
    Entity::Update();
}
void WallEntity::OnRemoveFromWorld(){
    Entity::OnRemoveFromWorld();

}