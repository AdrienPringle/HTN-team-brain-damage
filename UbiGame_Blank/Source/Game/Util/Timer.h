#pragma once

namespace Game
{
	class Timer
	{
	public:
		~Timer();
		static Timer* GetInstance() { if (!sm_instance) sm_instance = new Timer(); return sm_instance; }

		void SetCountdown(float t);//{time = t;};
		float GetCountdown();//{return time;};

	private:
		Timer();
		static Timer* sm_instance;

        float time;
	};	
}
