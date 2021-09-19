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
    if (GameEngine::GameEngineMain::GetGameTime() > counter * frequency) {
        spawn = true;
    }

    //randomize
    if (finishedSpawning == false && spawn) {
        std::uniform_int_distribution<int> angle(0, 359);
        std::uniform_int_distribution<int> color(1, 4);
        std::uniform_real_distribution<float> position(200, 800);

        //spawn
        BlobEntity* blob = new BlobEntity();
        blob->setVelAngle(angle(gen));
        blob->setSpeed(45);
        blob->SetPos(sf::Vector2f{ position(gen),position(gen) });
        blob->setColor(color(gen));
        GameEngine::GameEngineMain::GetInstance()->AddEntity(blob);
        counter++;
        spawn = false;
    }
    // if (counter == amount + 1) {
    //     finishedSpawning = true;
    // }

    if(GameEngine::GameEngineMain::GetGameTime() >= minute*60){
        finishedSpawning = true;
    }
}

void LevelEntity::setFrenquency(float f) {
    frequency = f;
}

void LevelEntity::setAmount(float a) {
    amount = a;
}

void LevelEntity::setTime(int m){
    minute = m;
}