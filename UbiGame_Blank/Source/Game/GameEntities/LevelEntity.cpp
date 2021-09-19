#include "LevelEntity.h"
#include "GameEngine/Util/CollisionManager.h"
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
#include<assert.h>
#include<iostream>


using namespace Game;

LevelEntity* LevelEntity::sm_instance = nullptr;
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine gen(seed1); //gen(time(NULL));
const float WIDTH = 800;
const float HEIGHT = 800;

LevelEntity::LevelEntity()
{
    counter = 1;
    finishedSpawning = false;

    //Render
    //m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    //m_renderComponent->SetTexture(GameEngine::eTexture::Yubel);
    //m_renderComponent->SetZLevel(1);
    //float x = GameEngine::GameEngineMain::GetInstance()->GetRenderWindow()->getSize().x/2;
    //float y = GameEngine::GameEngineMain::GetInstance()->GetRenderWindow()->getSize().y/2;
    //SetPos(sf::Vector2f{ x,y });
    //SetSize(sf::Vector2f{ WIDTH,HEIGHT });
}

LevelEntity::~LevelEntity()
{
}

void LevelEntity::OnAddToWorld()
{
    Entity::OnAddToWorld();
}

void LevelEntity::RegisterBlob(BlobEntity* blob)
{
    auto found = std::find(blobs.begin(), blobs.end(), blob);
    assert(found == blobs.end()); //Drop an assert if we add duplicate;
    if (found == blobs.end())
    {
        blobs.push_back(blob);
    }
}

void LevelEntity::UnRegisterBlob(BlobEntity* blob)
{
    auto found = std::find(blobs.begin(), blobs.end(), blob);
    assert(found != blobs.end()); //Drop an assert if we remove a non existing entity;
    if (found != blobs.end())
    {
        blobs.erase(found);
    }
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
        std::uniform_real_distribution<float> position(200, 800);

        //spawn
        BlobEntity* blob = new BlobEntity();
        blob->setVelAngle(angle(gen));
        blob->setSpeed(45);
        blob->SetPos(sf::Vector2f{ position(gen),position(gen) });
        GameEngine::GameEngineMain::GetInstance()->AddEntity(blob);
        counter++;
        spawn = false;
    }


    if (counter == amount + 1) {
        finishedSpawning = true;
    }

    //int previous = GetInstance()->GetBlobs().size();
    int blobcounter;
    if (GetInstance()->GetBlobs().size() < amount && GameEngine::GameEngineMain::GetGameTime() > 1) {
        blobcounter = amount - GetInstance()->GetBlobs().size();
        std::cout << blobcounter << std::endl;
    }
    //std::cout << GameEngine::CollisionManager::GetInstance()->GetCollidables().size();
    //std::cout << GetInstance()->GetBlobs().size();

}

void LevelEntity::setFrenquency(float f) {
    frequency = f;
}

void LevelEntity::setAmount(float a) {
    amount = a;
}