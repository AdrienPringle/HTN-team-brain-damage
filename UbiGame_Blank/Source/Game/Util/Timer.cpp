#include "Timer.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

Timer* Timer::sm_instance = nullptr;

Timer::Timer(){
    time = -1.f;
}
Timer::~Timer(){

}


void Timer::SetCountdown(float t){time = t;}
float Timer::GetCountdown(){return time;}