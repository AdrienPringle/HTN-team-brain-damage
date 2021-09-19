#include "PointManager.h"
#include "GameEngine/GameEngineMain.h"

#include "Game/GameEntities/WallEntity.h"
#include <assert.h>
using namespace Game;

PointManager* PointManager::sm_instance = nullptr;

PointManager::PointManager(){
    points = 0;
}
PointManager::~PointManager(){

}

void PointManager::RegisterBlob(BlobEntity* blob)
{
    auto found = std::find(blobs.begin(), blobs.end(), blob);
    assert(found == blobs.end()); //Drop an assert if we add duplicate;
    if (found == blobs.end())
    {
        blobs.push_back(blob);
    }
}

void PointManager::UnRegisterBlob(BlobEntity* blob)
{
    auto found = std::find(blobs.begin(), blobs.end(), blob);
    assert(found != blobs.end()); //Drop an assert if we remove a non existing entity;
    if (found != blobs.end())
    {
        blobs.erase(found);
    }
}
void PointManager::Update(){

}

void PointManager::AddGoal(){
    points ++;
}
void PointManager::ResetGoal(){
    points = 0;
}

int PointManager::GetGoalBlobs(){
    return points;
    // int goalBlobs = 0;
    // for(int i = 0; i < GetInstance()->GetBlobs().size(); i++ ){
    //     if(GetInstance()->GetBlobs()[i]->getState() == Goal ){
    //         goalBlobs++;
    //     }
    // }
    // return goalBlobs;
}

int PointManager::GetSuicidalBlobs() {
    int suicidalBlobs = 0;
    for (int i = 0; i < GetInstance()->GetBlobs().size(); i++) {
        if (GetInstance()->GetBlobs()[i]->getState() == Edge) {
            suicidalBlobs++;
        }
    }
    return suicidalBlobs;
}

int PointManager::GetWrongGoalBlobs() {
    int WrongGoalBlobs = 0;
    for (int i = 0; i < GetInstance()->GetBlobs().size(); i++) {
        if (GetInstance()->GetBlobs()[i]->getState() == WrongGoal) {
            WrongGoalBlobs++;
        }
    }
    return WrongGoalBlobs;
}
