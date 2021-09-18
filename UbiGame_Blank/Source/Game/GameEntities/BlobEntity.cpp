#include "BlobEntity.h"

#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"


using namespace Game;

const float WIDTH = 20.f;
const float HEIGHT = 20.f;

BlobEntity::BlobEntity()
{
    SetRotation(0.f);
    //Render
    m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    m_renderComponent->SetTexture(GameEngine::eTexture::Circle);
    m_renderComponent->SetZLevel(2);

    m_collideComponent = AddComponent<GameEngine::CollidablePhysicsComponent>();

    SetSize(sf::Vector2f(WIDTH, HEIGHT));
}

BlobEntity::~BlobEntity()
{
}

void BlobEntity::OnAddToWorld()
{
    Entity::OnAddToWorld();
}

void BlobEntity::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
}

void BlobEntity::Update()
{
    Entity::Update();
    float dt = GameEngine::GameEngineMain::GetTimeDelta();

    handleIntersect();
    

    SetPos(GetPos() + dt * velocity);

}

void BlobEntity::reflect(sf::Vector2f normal){
    sf::Vector2f tangent = sf::Vector2f(normal.y, -normal.x);


    float dot = tangent.x*velocity.x + tangent.y*velocity.y;
    float mag = tangent.x*tangent.x + tangent.y*tangent.y;

    float diffMag = 2 * dot / mag;

    sf::Vector2f diff = sf::Vector2f(tangent.x * diffMag, tangent.y * diffMag);
    velocity = diff - velocity;
}

void BlobEntity::handleIntersect(){
    sf::Vector2f intersect = m_collideComponent->didIntersect();
    if(intersect.x != 0.f || intersect.y != 0.f){

        reflect(intersect);

        m_collideComponent->resolveIntersect();
    }
}

void BlobEntity::setVelAngle(float a){
    angle = a;
    
    if(speed > 0){
        velocity.x = speed * cos(angle * M_PI/180);
        velocity.y = speed * sin(angle * M_PI/180);
    }
}
void BlobEntity::setSpeed(float s){
    speed = s;

    velocity.x = speed * cos(angle * M_PI/180);
    velocity.y = speed * sin(angle * M_PI/180);
}

float BlobEntity::getAngle()
{
    return angle;
}