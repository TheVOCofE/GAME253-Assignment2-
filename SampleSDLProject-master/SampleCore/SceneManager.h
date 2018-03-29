#pragma once
#include "Manager.h"
#include <vector>
#include "Scene.h"

namespace core {
	class SceneManager : public Manager
	{
		friend scene::Scene;
		static SceneManager* m_instance;
	private:
		SceneManager();
		SceneManager(scene::Scene* currentScene, SDL_Surface* screenSurface_);
	protected:
		std::vector<scene::Scene*> scenes;
	public:
		int currentSceneNumber;
		~SceneManager();
		scene::Scene* currentScene;
		SDL_Surface* screenSurface = NULL;
		bool Init() override;
		void Update() override;
		void Draw() const override;
		void Draw(SDL_Surface* screenSurface_) const;
		bool Shutdown() override;

		void AddScene(scene::Scene* scene_);

		void LoadNextScene();

		static SceneManager* GetInstance()
		{
			if (m_instance == nullptr)
				m_instance = new SceneManager();
			return m_instance;
		}



	};
}
