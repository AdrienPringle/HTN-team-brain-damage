#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "BlobEntity.h"
#include "GameEngine/Util/CollisionManager.h"
#include <vector>

namespace Game
{

    class LevelEntity : public GameEngine::Entity
    {
    public:
        LevelEntity();
        ~LevelEntity();
        static LevelEntity* GetInstance() { if (!sm_instance) sm_instance = new LevelEntity(); return sm_instance; }

        void RegisterBlob(BlobEntity* blob);
        void UnRegisterBlob(BlobEntity* blob);

        std::vector<BlobEntity*>& GetBlobs() { return blobs; }

        virtual void OnAddToWorld() override;
        virtual void OnRemoveFromWorld() override;
        virtual void Update() override;

        void setFrenquency(float f);
        void setAmount(float a);
        void setLevel(int l);

    protected:
        GameEngine::SpriteRenderComponent *m_renderComponent;

        float frequency;
        float amount;
        bool finishedSpawning;
        int counter;
        bool spawn;

        static LevelEntity* sm_instance;

        std::vector<BlobEntity*> blobs;

        
    };
}
