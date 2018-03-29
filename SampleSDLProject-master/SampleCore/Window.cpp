#include "stdafx.h"
#include "Window.h"
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

namespace core {
	Window::Window() : System(SystemType::WINDOW)
	{
		Init();
	}


	Window::~Window()
	{
	}

	bool Window::Init() {
		bool initResult = 0;
		//Initialize SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

			///initResult = ENGINE_INIT_ERROR;
		}
		else
		{
			//Create window
			window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

				///initResult = ENGINE_INIT_ERROR;
			}
			else
			{
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);

				//Wait two seconds
				//SDL_Delay(2000);
			}
		}
		return initResult;
	}

	void Window::Update() {

	}

	void Window::Draw() const {

	}

	bool Window::Shutdown() {
		return true;
	}

	System* Window::make_system(SystemType type) {
		return new Window();
	}
}