#pragma once

#include "Scene.h"
#include "Input.h"
#include "Window.h"
#include "Manager.h"
#include <SDL\SDL.h>

#define ENGINE_INIT_ERROR     1
#define ENGINE_SHUTDOWN_ERROR 2

namespace core {
	class Engine
	{
	protected:


	public:
		Engine(scene::Scene* _mainScene, scene::Scene* _secondScene);
		~Engine();

		int init();
		void print();
		int run();
		

	private:
		bool isRunning;
		scene::Scene* mainScene;
		scene::Scene* secondScene;
		std::vector<Manager*> managers;
		Input* inputSystem;
		Window* windowSystem;
		
		/*bool Init();*/
		void Update();
		void Draw() const;
		bool Shutdown();
	};
}
