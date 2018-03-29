#pragma once

#include "System.h"
namespace core {
	class Window : public System
	{
	public:
		Window();
		~Window();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;
		System* make_system(SystemType type);

		// Move to window system
		//The window we'll be rendering to
		SDL_Window* window = NULL;

		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;
	};
}

