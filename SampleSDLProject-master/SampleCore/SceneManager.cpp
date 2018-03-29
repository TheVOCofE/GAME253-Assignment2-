#include "stdafx.h"
#include "SceneManager.h"
#include "SystemManager.h"
#include "Input.h"

namespace core {

	SceneManager *SceneManager::m_instance = 0;

	SceneManager::SceneManager()
	{
	/*	screenSurface = screenSurface_;
		scenes.push_back(currentScene_);
		currentScene = scenes[0];*/
		/*scenes.push_back(new Input());
		scenes.push_back(new Window());*/
	}


	SceneManager::~SceneManager()
	{
	}

	bool SceneManager::Init() {
		currentSceneNumber = 0;
		currentScene = scenes[0];
		currentScene->Init();

		return true;
	}

	void SceneManager::Update() {
		if (SystemManager::GetInstance()->GetSystem<Input>()->Is1Pressed()) {
			LoadNextScene();
		}
			//SystemManager::GetInstance()->GetSystem<Window>()->s
		currentScene->Update();
	}

	void SceneManager::Draw() const
	{
	}

	void SceneManager::Draw(SDL_Surface* screenSurface_) const {
		currentScene->Draw(screenSurface_);
	}

	bool SceneManager::Shutdown() {
		for (scene::Scene* s : scenes) {
			if (!s->Shutdown()) {
				return false;
			}
			delete s;
			s = nullptr;
		}
		scenes.clear();

		return true;
	}

	void SceneManager::AddScene(scene::Scene* scene_) {
		scenes.push_back(scene_);
	}

	void SceneManager::LoadNextScene() {
		if (currentSceneNumber+1 < scenes.size() && scenes[0] != nullptr) {
			currentSceneNumber++;
		}
		else if(scenes[0] != nullptr)
		{
			currentSceneNumber = 0;
		}
		
		currentScene=scenes[currentSceneNumber];
	}

}