#include "BlobMovementComponent.h"

#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs

#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"


#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"

#include <iostream>

#include <math.h>

#define PI 3.14159265

using namespace Game;

BlobMovementComponent::BlobMovementComponent()
{   
}

void BlobMovementComponent::setAngle(float angle) {
    float x = .1 *cos(angle * PI / 180);
    float y = .1 * sin(angle * PI / 180);

    displacement = { x,y };
    
}

void BlobMovementComponent::Update() {
    Component::Update();

    //sf::Vector2f displacement{ 0.01f,0.01f };

    //The amount of speed that we will apply when input is receive;

    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
    
}

void BlobMovementComponent::OnAddToWorld() {

}