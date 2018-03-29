#pragma once
#include <SDL\SDL.h>
#include <string>
#include "Window.h"
#include "SystemManager.h"

namespace scene {
	class GameObject
	{
	public:
		GameObject(std::string image_, float xPos_, float yPos_);
		virtual ~GameObject();
		bool Init();
		void Update();
		void Draw(SDL_Surface* screenSurface_) const;
		bool Shutdown();
		SDL_Surface* image;
		float xPos;
		float yPos;
	};

}