#include "BlobEntity.h"
#include "Game/Util/PointManager.h"

#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

#include <iostream>
using namespace Game;

const float WIDTH = 50.f;
const float HEIGHT = 50.f;

BlobEntity::BlobEntity()
{
    state = BlobState::Active;
    SetRotation(0.f);
    //Render
    m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
   
    m_renderComponent->SetZLevel(2);

    m_collideComponent = AddComponent<GameEngine::CollidablePhysicsComponent>();
    m_collideComponent->SetColliderType(GameEngine::ColliderType::Circle);
    m_collideComponent->SetEntityType(GameEngine::EntityType::Blob);
    

    SetSize(sf::Vector2f(WIDTH, HEIGHT));
}

BlobEntity::~BlobEntity()
{
}

void BlobEntity::setColor(int c){
    
    m_renderComponent->SetTexture(GameEngine::blobTextures[c-1]);
    m_collideComponent->setColor(c);
    color = c;
}

void BlobEntity::OnAddToWorld()
{
    Entity::OnAddToWorld();
    PointManager::GetInstance()->RegisterBlob(this);
}

void BlobEntity::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
    PointManager::GetInstance()->UnRegisterBlob(this);
}

void BlobEntity::updateAnimate(){
    const float SLITHERFREQ = 0.25; //0.25 slither / second
    const float SLITHERTIME = 1/SLITHERFREQ;

    float timeElapsed = GameEngine::GameEngineMain::GetGameTime() - SLITHERTIME;
    // float interp = 4*(timeElapsed * SLITHERFREQ * 0.5)*(1 - timeElapsed*SLITHERFREQ*0.5);
    float cyclePos = fmod(2 * M_PI * timeElapsed * SLITHERFREQ, 2 * M_PI);
    float s = sin(cyclePos);
    float c = cos(cyclePos);
    SetSize(sf::Vector2f(WIDTH + 10*s*s, HEIGHT + 5*c*c*c*c));    

    m_renderComponent->UpdateSpriteParams();

    
}

void BlobEntity::Update()
{
    Entity::Update();
    float dt = GameEngine::GameEngineMain::GetTimeDelta();

    switch (state){
        case BlobState::Active:
            handleIntersect();
            SetPos(GetPos() + dt * velocity);
            m_renderComponent->SetTileIndex(sf::Vector2i(velocity.x > 0 ? 0 : 1 ,0));
            updateAnimate();
            break;
        case BlobState::Goal:
            {sf::Vector2f newSize = GetSize()-sf::Vector2f(dt*100.f, dt*100.f);
            if(newSize.x <= 5){
                GameEngine::GameEngineMain::GetInstance()->RemoveEntity(this);
                return;
            }
            SetSize(newSize);
            
            SetPos(GetPos() + dt * velocity);
            m_renderComponent->UpdateSpriteParams();}
            break;
        case BlobState::WrongGoal:
            {SetSize(GetSize()+sf::Vector2f(dt*20.f, dt*20.f));

            sf::Vector2u screenSize = GameEngine::GameEngineMain::GetInstance()->GetRenderWindow()->getSize();
            
            if(GetPos().x < 0 || GetPos().y < 0 || GetPos().x > screenSize.x || GetPos().y > screenSize.y){
                GameEngine::GameEngineMain::GetInstance()->RemoveEntity(this);
            }
            m_renderComponent->UpdateSpriteParams();

            velocity.y += dt * 200;
            SetPos(GetPos() + dt * 5 * velocity);
            SetRotation(GetRot() + dt * 50 * velocity.x);
            break;}
        case BlobState::Edge:
            {sf::Vector2f newSize = GetSize()-sf::Vector2f(dt*100.f, dt*100.f);
            if(newSize.x <= 5){
                GameEngine::GameEngineMain::GetInstance()->RemoveEntity(this);
                return;
            }
            SetSize(newSize);SetPos(GetPos() + (float)( 0.5 * dt) * velocity);
            SetRotation(GetRot() + dt * 720.f);
            m_renderComponent->UpdateSpriteParams();
            break;}
    }
    
    checkBoundaries(140, 900, 60, 900);
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
        
        switch(m_collideComponent->getCollidedComponent()->GetEntityType()){
            case GameEngine::EntityType::Blob:;
            case GameEngine::EntityType::Collider:
                reflect(intersect);
                m_collideComponent->resolveIntersect();
                break;
            case GameEngine::EntityType::Goal:
                m_collideComponent->SetColliderType(GameEngine::ColliderType::NoClip);
                

                if(m_collideComponent->getCollidedComponent()->getColor() == color){
                    state = BlobState::Goal;
                    PointManager::GetInstance()->AddGoal();
                } else {
                    state = BlobState::WrongGoal;
                }
                break;
        }

        
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

void BlobEntity::checkBoundaries(float left, float right, float top, float bottom){
    if ((GetPos().x < left || GetPos().x > right || GetPos().y < top || GetPos().y>bottom) && state == Active){
        state = BlobState::Edge;
        std::cout << "edgy";
    }
}

BlobState BlobEntity::getState(){
    return state;
}