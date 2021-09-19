#include "LevelEntity.h"
#include "BlobEntity.h"

#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

#include "Game/Util/Timer.h"

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

sf::Vector2f LevelEntity::generatePos(){
    float x = 500, y = 500;

    std::uniform_real_distribution<float> xpos(250, 750);
    std::uniform_real_distribution<float> ypos(200, 800);
    while ( abs(x - 500) + abs(y - 500) < 100){
        x = xpos(gen);
        y = ypos(gen);
    }
    return sf::Vector2f(x,y);
}
float LevelEntity::generateAngle(sf::Vector2f pos){
    float diffX = pos.x - 500.f;
    float diffY = pos.y - 500.f;

    std::uniform_int_distribution<int> angle(-45, 45);

    float a = atan2f(diffY, diffX);
    a += angle(gen);
    return a;

}

void LevelEntity::Update()
{
    Entity::Update();

    //Abide by Frequency
    if (GameEngine::GameEngineMain::GetGameTime() > counter * frequency) {
        spawn = true;
    }

    //randomize
    finishedSpawning = Game::Timer::GetInstance()->GetCountdown() <= 0;
    if (finishedSpawning == false && spawn) {
        
        std::uniform_int_distribution<int> color(1, 4);
        

        //spawn
        BlobEntity* blob = new BlobEntity();
        blob->setSpeed(60);
        sf::Vector2f pos = generatePos();
        blob->SetPos(pos);
        blob->setVelAngle(generateAngle(pos));
        blob->setColor(color(gen));
        GameEngine::GameEngineMain::GetInstance()->AddEntity(blob);
        counter++;
        spawn = false;
    }
    // if (counter == amount + 1) {
    //     finishedSpawning = true;
    // }

    // if(GameEngine::GameEngineMain::GetGameTime() >= minute*60){
    //     finishedSpawning = true;
    // }
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