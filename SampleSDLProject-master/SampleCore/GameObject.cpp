#include "stdafx.h"
#include "GameObject.h"


namespace scene {

	GameObject::GameObject(std::string image_, float xPos_, float yPos_)
	{
		image = SDL_LoadBMP(image_.c_str());
		xPos = xPos_;
		yPos = yPos_;
	}


	GameObject::~GameObject()
	{
	}

	bool GameObject::Init() {
		return true;
	}

	void GameObject::Update() {

	}

	void GameObject::Draw(SDL_Surface* screenSurface_) const {
		SDL_Rect rect;

		rect.h = image->h;
		rect.w = image->w;
		rect.x = xPos;
		rect.y = yPos;
		SDL_BlitSurface(image, nullptr, core::SystemManager::GetInstance()->GetSystem<core::Window>()->screenSurface, &rect);
	}

	bool GameObject::Shutdown() {
		return true;
	}
}
