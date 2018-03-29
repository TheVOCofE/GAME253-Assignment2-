#include "stdafx.h"
#include "Engine.h"

#include <iostream>
#include "SystemManager.h"
#include "SceneManager.h"
#include <stdio.h>


namespace core {
	

	Engine::Engine(scene::Scene* _mainScene, scene::Scene* _secondScene) : mainScene(_mainScene), secondScene(_secondScene)
	{
		isRunning = false;
		managers.push_back(SystemManager::GetInstance());
		managers.push_back(SceneManager::GetInstance());
		SceneManager::GetInstance()->AddScene(mainScene);
		SceneManager::GetInstance()->AddScene(secondScene);
	}


	Engine::~Engine()
	{
	}

	int Engine::init()
	{
		return 0;
	}

	int Engine::run() {
		isRunning = true;
		inputSystem = dynamic_cast<SystemManager*>(managers[0])->GetSystem<Input>();
		windowSystem = dynamic_cast<SystemManager*>(managers[0])->GetSystem<Window>();
		SceneManager::GetInstance()->Init();

		while ( !inputSystem->QuitRequested())
		{
			// Update
			Update();
			// Render
			Draw();

		}

		return Shutdown();

	}

	/*bool Engine::Init() {
		mainScene->Init();

		return true;
	}*/

	void Engine::Update() {
		//mainScene->Update();
		for (Manager* m : managers) {
			m->Update();
		}
		
		//mainScene->Update();
		
		//Fill the surface white
		SDL_FillRect(windowSystem->screenSurface, NULL, SDL_MapRGB(windowSystem->screenSurface->format, 0x00, 0xFF, 0xFF));


		
	}

	void Engine::Draw() const{
		for (Manager* m : managers) {
			m->Draw();
		}
		SceneManager::GetInstance()->Draw(windowSystem->screenSurface);
		//mainScene->Draw(screenSurface);

		//Update the surface
		SDL_UpdateWindowSurface(windowSystem->window);
	}

	bool Engine::Shutdown() {
		if (!mainScene->Shutdown()) {
			return 1;
		}

		//Destroy window
		SDL_DestroyWindow(windowSystem->window);

		//Quit SDL subsystems
		SDL_Quit();

		return 0;
	}

	void Engine::print()
	{
		std::cout << "this is working" << std::endl;
	}

}