#include "stdafx.h"
#include "Input.h"
#include <stdio.h>
#include <SDL\SDL.h>
namespace core {
	Input::Input() : System(SystemType::INPUT), quitRequested(false)
	{

	}

	Input::~Input()
	{
	}

	bool Input::Init() {
		return true;
	}

	void Input::Update() {
		SDL_Event e;
		m_1Pressed = false;
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT) {
				quitRequested = true;
			}

			switch (e.type) {
			case SDL_KEYDOWN:
				//printf("Key Down");
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					printf("Key Up");
					m_upPressed = true;
					break;
				case SDLK_DOWN:
					printf("Key Down");
					m_downPressed = true;
					break;
				case SDLK_LEFT:
					printf("Key Left");
					m_leftPressed = true;
					break;
				case SDLK_RIGHT:
					printf("Key Right");
					m_rightPressed = true;
					break;
				case SDLK_1:
					printf("Load next scene");
					m_1Pressed = true;
					break;
				}
				break;
			case SDL_KEYUP:
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					m_leftPressed = false;
					printf("left was released");
					break;
				case SDLK_RIGHT:
					m_rightPressed = false;
					printf("right was released");
					break;
				case SDLK_UP:
					m_upPressed = false;
					printf("up was released");
					break;
				case SDLK_DOWN:
					m_downPressed = false;
					printf("down was released");
					break;
				case SDLK_1:
					//printf("Load next scene");
					m_1Pressed = false;
					break;
				}

				
				break;
			case SDL_QUIT:
				quitRequested = true;
				break;
			
			}
			break;
		}
	}

	void Input::Draw() const {

	}

	bool Input::Shutdown() {
		return true;
	}

	System* Input::make_system(SystemType type) {
		return new Input();
	}
}