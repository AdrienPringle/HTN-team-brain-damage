#include "GoalEntity.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


using namespace Game;

const float WIDTH = 200.f;
const float HEIGHT = 200.f;

GoalEntity::GoalEntity()
{
    initialPos = sf::Vector2f(NAN, NAN);
    state = GoalState::Idle;
    //Render
    m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    m_renderComponent->SetZLevel(1);
    m_renderComponent->SetTileIndex(sf::Vector2i(0,0));


    m_collidableComponent = AddComponent<GameEngine::CollidableComponent>();
    m_collidableComponent->SetColliderType(GameEngine::ColliderType::Circle);
    m_collidableComponent->SetEntityType(GameEngine::EntityType::Goal);

    SetSize(sf::Vector2f(WIDTH, HEIGHT));
}

GoalEntity::~GoalEntity()
{

}


void GoalEntity::setColor(int c){
    m_renderComponent->SetTexture(GameEngine::goalTextures[c-1]);
    m_collidableComponent->setColor(c);
    color = c;
}

void GoalEntity::SetPos(sf::Vector2f pos){
    if(isnan(initialPos.x)){
        initialPos = pos;
    }
    Entity::SetPos(pos);
}

void GoalEntity::Update()
{
    Entity::Update();
    sf::Vector2f intersecting = m_collidableComponent->didIntersect();
    const float MONCHFREQ = 2; //2 monch / second
    const float MONCHTIME = 1/MONCHFREQ;
    float timeElapsed = GameEngine::GameEngineMain::GetGameTime() - monchTime;
    float interp = 4*(timeElapsed * MONCHFREQ * 0.5)*(1 - timeElapsed*MONCHFREQ*0.5);
    float cyclePos = fmod(2 * M_PI * timeElapsed * MONCHFREQ, 2 * M_PI);

    if(intersecting.x != 0.f || intersecting.y != 0.f){
        m_collidableComponent->resolveIntersect();

        if(m_collidableComponent->getCollidedComponent()->getColor() == color){
            state = GoalState::Monch;
        }else{
            state = GoalState::Anger;
        }
        
        monchTime = GameEngine::GameEngineMain::GetGameTime();
        m_renderComponent->SetTileIndex(sf::Vector2i(1,0));
        
    }
    
    switch(state){
        case GoalState::Idle:
            
            break;
        case GoalState::Monch:
            SetSize(sf::Vector2f(WIDTH + 30*interp*sin(cyclePos), HEIGHT + 30*interp*cos(cyclePos)));
            SetPos(initialPos - sf::Vector2f(0, 15*interp*cos(cyclePos)));
            
            if(timeElapsed > MONCHTIME * 2){
                state == GoalState::Idle;
                SetPos(initialPos);
                SetSize(sf::Vector2f(WIDTH, HEIGHT));
                m_renderComponent->SetTileIndex(sf::Vector2i(0,0));
            }

            m_renderComponent->UpdateSpriteParams();

            break;
        case GoalState::Anger:
            SetPos(initialPos - sf::Vector2f(15*interp*sin(cyclePos), 15*interp*cos(cyclePos)*cos(cyclePos)));
            SetRotation(10*interp*sin(cyclePos*4));
            if(timeElapsed > MONCHTIME * 2){
                state == GoalState::Idle;
                SetRotation(0);
                SetPos(initialPos);
                SetSize(sf::Vector2f(WIDTH, HEIGHT));
                m_renderComponent->SetTileIndex(sf::Vector2i(0,0));
            }

            m_renderComponent->UpdateSpriteParams();
            break;
    }

    
    
}
