#include "MovementComponent.h"
#include "GameEngine/GameEngineMain.h"

#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


using namespace Game;

MovementComponent::MovementComponent()
{
    velocity = sf::Vector2f(0.f, 0.f);
	speed = 0;
	angle = 0;
}


MovementComponent::~MovementComponent()
{

}


void MovementComponent::OnAddToWorld()
{
	Component::OnAddToWorld();
}


void MovementComponent::OnRemoveFromWorld()
{
	Component::OnAddToWorld();
}


void MovementComponent::Update()
{
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();

	GameEngine::Entity* e = GetEntity();
    e->SetPos(e->GetPos() + dt * velocity);
}

void MovementComponent::setVel(sf::Vector2f vel){
    velocity = vel;

	angle = atan2(vel.x, vel.y);
	speed = sqrt(vel.x*vel.x + vel.y*vel.y);
}

void MovementComponent::reflect(sf::Vector2f normal){
    sf::Vector2f tangent = sf::Vector2f(normal.y, -normal.x);


    float dot = tangent.x*velocity.x + tangent.y*velocity.y;
    float mag = tangent.x*tangent.x + tangent.y*tangent.y;

    float diffMag = 2 * dot / mag;

    sf::Vector2f diff = sf::Vector2f(tangent.x * diffMag, tangent.y * diffMag);
    velocity = diff - velocity;
}

void MovementComponent::setVelAngle(float a){
    angle = a;
    
    if(speed > 0){
        velocity.x = speed * cos(angle * M_PI/180);
        velocity.y = speed * sin(angle * M_PI/180);
    }
}
void MovementComponent::setSpeed(float s){
    speed = s;

    velocity.x = speed * cos(angle * M_PI/180);
    velocity.y = speed * sin(angle * M_PI/180);
}

float MovementComponent::getAngle()
{
    return angle;
}