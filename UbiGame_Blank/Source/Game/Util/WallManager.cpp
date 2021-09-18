#include "WallManager.h"
#include "GameEngine/GameEngineMain.h"

#include "Game/GameEntities/WallEntity.h"

using namespace Game;

WallManager* WallManager::sm_instance = nullptr;

WallManager::WallManager(){
    wasMouseDown = true;
}
WallManager::~WallManager(){

}

void WallManager::Update(){

    //spawn wall on mouse down
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        wasMouseDown = false;
    } else if (!wasMouseDown) {
        wasMouseDown = true;
        SpawnWall();
    }
}

void WallManager::SpawnWall(){
    sf::RenderWindow *window = GameEngine::GameEngineMain::GetInstance()->GetRenderWindow();
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*window));

    WallEntity* wall = new WallEntity();
    wall->SetPos(mousePos);
    GameEngine::GameEngineMain::GetInstance()->AddEntity(wall);
}