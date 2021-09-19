#include "TimerEntity.h"

#include "GameEngine/GameEngineMain.h"
#include "SFML/Graphics/Color.hpp"
#include <string>
#include <iomanip>
#include <iostream>

#include "Game/Util/Timer.h"
const float WIDTH = 800;
const float HEIGHT = 800;

std::string scoreString;
int minute = 0;
int second = 59;
int countdown =1;
using namespace Game;

TimerEntity::TimerEntity()
{
    m_renderComponent = AddComponent<GameEngine::TextRenderComponent>();
    m_renderComponent->SetFont("comici.ttf");
    m_renderComponent->SetCharacterSizePixels(30);
    m_renderComponent->SetColor(sf::Color(255,255,255));
	m_renderComponent->SetString("Timer: 0");
	m_renderComponent->SetZLevel(10);
    SetPos(sf::Vector2f{470.f,0.f});
}

TimerEntity::~TimerEntity()
{
}

void TimerEntity::OnAddToWorld()
{
    Entity::OnAddToWorld();
}

void TimerEntity::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
}

void TimerEntity::setTime(float t){
    countdownSeconds = (int)( 60 * t );
}
void TimerEntity::setStartTime(float time){
    startTime = time;
}
void TimerEntity::Update()
{
    Entity::Update();
    // if (second > 0 && minute >= 0){
    //     second = (60*countdown-1) - static_cast<int>(GameEngine::GameEngineMain::GetInstance()->GetGameTime());
    //     if(second <= 9){
    //         m_renderComponent->SetString( std::to_string(minute) + ":0" + std::to_string(second));
    //     }else{
    //         m_renderComponent->SetString( std::to_string(minute) + ":" + std::to_string(second));
    //     }
    // }else if (minute > 0 && second <= 0){
    //     countdown++;
    //     second = (60*countdown-1);
    //     minute--;
    //     m_renderComponent->SetString( std::to_string(minute) + ":" + std::to_string(second));
    // }
    // if(second <= 0 && minute <= 0){
    //     m_renderComponent->SetString("0:00");
    // }
    float timeDiff = static_cast<int>(GameEngine::GameEngineMain::GetInstance()->GetGameTime()) - startTime;
    float timeLeft = countdownSeconds - timeDiff;
    second = ((int) timeLeft) % 60;
    minute = ((int) timeLeft) / 60;

    if(second < 0){
        m_renderComponent->SetString("0:00");
    }else if(second < 10){
        m_renderComponent->SetString( std::to_string(minute) + ":0" + std::to_string(second));
    }else{
        m_renderComponent->SetString( std::to_string(minute) + ":" + std::to_string(second));
    }

    Game::Timer::GetInstance()->SetCountdown(timeLeft);
}

bool TimerEntity::timeUp(){
    // if (second <= 0 && minute <= 0){
    //     return true;
    // }else{
    //     return false;
    // }
    float timeDiff = static_cast<int>(GameEngine::GameEngineMain::GetInstance()->GetGameTime()) - startTime;
    return (timeDiff > countdownSeconds); 
}
