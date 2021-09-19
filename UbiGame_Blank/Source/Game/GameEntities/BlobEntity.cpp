#include "BlobEntity.h"
#include "LevelEntity.h"

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
    LevelEntity::GetInstance()->RegisterBlob(this);
}

void BlobEntity::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
    LevelEntity::GetInstance()->UnRegisterBlob(this);
}

void BlobEntity::Update()
{
    Entity::Update();
    float dt = GameEngine::GameEngineMain::GetTimeDelta();

    switch (state){
        case BlobState::Active:
            handleIntersect();
            SetPos(GetPos() + dt * velocity);
            break;
        case BlobState::Goal:
            SetSize(GetSize()-sf::Vector2f(dt*10.f, dt*10.f));
            if(GetSize().x > WIDTH*4){
                GameEngine::GameEngineMain::GetInstance()->RemoveEntity(this);
            }
            SetPos(GetPos() + dt * velocity);
            m_renderComponent->UpdateSpriteParams();
            break;
        case BlobState::WrongGoal:
            SetSize(GetSize()+sf::Vector2f(dt*20.f, dt*20.f));
            if(GetSize().x > WIDTH*4){
                GameEngine::GameEngineMain::GetInstance()->RemoveEntity(this);
            }

            m_renderComponent->UpdateSpriteParams();
            break;
    }
    
    SetPos(GetPos() + dt * velocity);
    checkBoundaries(100, 900, 100, 900);
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
    if (GetPos().x < left || GetPos().x > right || GetPos().y < top || GetPos().y>bottom){
        GameEngine::GameEngineMain::GetInstance()->RemoveEntity(this);
    }
}