#pragma once

#include "Game/GameEntities/BlobEntity.h"
#include <vector>

namespace Game
{
	class PointManager
	{
	public:
		~PointManager();
		static PointManager* GetInstance() { if (!sm_instance) sm_instance = new PointManager(); return sm_instance; }

		void Update();

		void RegisterBlob(BlobEntity* blob);
        void UnRegisterBlob(BlobEntity* blob);

        std::vector<BlobEntity*>& GetBlobs() { return blobs; }
		int GetGoalBlobs();
		int GetSuicidalBlobs();
		int GetWrongGoalBlobs();
		
	private:
		PointManager();
		static PointManager* sm_instance;

        std::vector<BlobEntity*> blobs;
	
	};	
}
