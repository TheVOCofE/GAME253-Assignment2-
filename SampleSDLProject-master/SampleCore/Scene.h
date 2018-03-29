#pragma once
#include <SDL\SDL.h>
#include <vector>
namespace scene {
	class Scene
	{
	private:
		std::vector<class GameObject*> gameObjects;
	public:
		Scene();
		virtual ~Scene();
		virtual bool Init();
		virtual void Update();
		virtual void Draw(SDL_Surface* screenSurface_) const;
		virtual bool Shutdown();
		//virtual void HandleEvents();
	};
}
