#include "LevelEntity.h"
#include "BlobEntity.h"

#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

#include<random>
#include<ctime>
#include<chrono>


using namespace Game;

unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine gen(seed1); //gen(time(NULL));
const float WIDTH = 800;
const float HEIGHT = 800;

LevelEntity::LevelEntity()
{
    counter = 1;
    finishedSpawning = false;

    //Render
   /* m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    m_renderComponent->SetTexture(GameEngine::eTexture::Yubel);
    m_renderComponent->SetZLevel(1);*/
    float x = GameEngine::GameEngineMain::GetInstance()->GetRenderWindow()->getSize().x/2;
    float y = GameEngine::GameEngineMain::GetInstance()->GetRenderWindow()->getSize().y/2;
    SetPos(sf::Vector2f{ x,y });
    SetSize(sf::Vector2f{ WIDTH,HEIGHT });
}

LevelEntity::~LevelEntity()
{
}

void LevelEntity::OnAddToWorld()
{
    Entity::OnAddToWorld();
}

void LevelEntity::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
}

void LevelEntity::Update()
{
    Entity::Update();

    //Abide by Frequency
    if (GameEngine::GameEngineMain::GetGameTime() > counter*frequency) {
        spawn = true;
    }

    //randomize
    if (finishedSpawning == false && spawn) {
        std::uniform_int_distribution<int> angle(0, 359);
        std::uniform_real_distribution<float> position(630, 770);

        //spawn
        BlobEntity* blob = new BlobEntity();
        blob->setVelAngle(angle(gen));
        blob->setSpeed(85);
        blob->SetPos(sf::Vector2f{ position(gen),position(gen) });
        GameEngine::GameEngineMain::GetInstance()->AddEntity(blob);
        counter++;
        spawn = false;
    }
    if (counter == amount + 1) {
        finishedSpawning = true;
    }
}

void LevelEntity::setFrenquency(float f) {
    frequency = f;
}

void LevelEntity::setAmount(float a) {
    amount = a;
}