#include "BlobMovementComponent.h"

#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs

#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

#include <iostream>

#include <math.h>

#define PI 3.14159265

using namespace Game;

BlobMovementComponent::BlobMovementComponent()
    :m_lastFaceIndex(0)
{   
    srand(time(NULL));
    

    float(rand()) / float((RAND_MAX) * .5);
    float sign1;
    float sign2;
    if ((rand() % 4 + 1) > 3) {
        sign1 = 1;
        sign2 = 1;
    } else if ((rand() % 4 + 1) > 2) {
        sign1 = 1;
        sign2 = -1;
    } else if ((rand() % 4 + 1) > 1) {
        sign1 = -1;
        sign2 = 1;
    } else {
        sign1 = -1;
        sign2 = -1;
    }
    float x = float(rand()) / (float((RAND_MAX)*20) * sign1);
    float y = float(rand()) / (float((RAND_MAX)*20) * sign2);
    
    displacement = { x/10, y/10};
}

void BlobMovementComponent::setAngle(float angle) {
    //setangle
    float x = .01 *cos(angle * PI / 180);
    float y = .01 * sin(angle * PI / 180);

    displacement = { x,y };
    
}

void BlobMovementComponent::Update() {
    Component::Update();

    //sf::Vector2f displacement{ 0.01f,0.01f };

    //The amount of speed that we will apply when input is receive;

    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
    
}

void BlobMovementComponent::OnAddToWorld() {}