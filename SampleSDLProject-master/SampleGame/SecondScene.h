#pragma once

#include "stdafx.h"
#include <Scene.h>
#include <GameObject.h>
#include <vector>

class SecondScene : public scene::Scene
{
public:
	SecondScene();
	~SecondScene();

	bool Init();
	void Update();
	void Draw(SDL_Surface* screenSurface_) const;
	bool Shutdown();
	//void HandleEvents();


	std::vector<scene::GameObject*> gameObjects;
};

