#pragma once

namespace Game
{
	class WallManager
	{
	public:
		~WallManager();
		static WallManager* GetInstance() { if (!sm_instance) sm_instance = new WallManager(); return sm_instance; }

		void Update();

	private:
		WallManager();
		static WallManager* sm_instance;

        void SpawnWall();
        bool wasMouseDown;
	};	
}
