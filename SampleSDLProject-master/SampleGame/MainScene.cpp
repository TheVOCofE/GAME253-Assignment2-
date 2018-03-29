#include "stdafx.h"
#include "MainScene.h"
#include <SystemManager.h>
#include <Input.h>
#include <Window.h>



MainScene::MainScene()
{
	scene::GameObject* gameObject = new scene::GameObject("test.bmp", 10.0f, 10.0f);
	gameObjects.push_back(gameObject);

}


MainScene::~MainScene()
{
}

bool MainScene::Init() {
	std::cout << "Scene init" << std::endl;
	return true;
}

void MainScene::Update() {
	///using namespace core;

	for(scene::GameObject* g : gameObjects) {
		g->Update();
	}

	/*SystemManager* sm = SystemManager::GetInstance();
	System* input = dynamic_cast<core::Input*>(sm->GetSystem<core::Input>());
	Window* window = dynamic_cast<core::Window*>(sm->GetSystem<core::Window>());
	*/
	if (core::SystemManager::GetInstance()->GetSystem<core::Input>()->IsLeftPressed()) {
		for (scene::GameObject* g : gameObjects) {
			g->xPos-=0.01;
		}
	}
	if (core::SystemManager::GetInstance()->GetSystem<core::Input>()->IsRightPressed()) {
		for (scene::GameObject* g : gameObjects) {
			g->xPos+=0.01;
		}
	}
	if (core::SystemManager::GetInstance()->GetSystem<core::Input>()->IsUpPressed()) {
		for (scene::GameObject* g : gameObjects) {
			g->yPos-=0.01;
		}
	}
	if (core::SystemManager::GetInstance()->GetSystem<core::Input>()->IsDownPressed()) {
		for (scene::GameObject* g : gameObjects) {
			g->yPos+=0.01;
		}
	}
	//std::cout << "Scene update" << std::endl;
}

void MainScene::Draw(SDL_Surface* screenSurface_) const {
	for (scene::GameObject* g : gameObjects) {
		g->Draw(screenSurface_);
	}

	
	//std::cout << "Scene draw" << std::endl;
}

bool MainScene::Shutdown() {
	std::cout << "Scene shutdown" << std::endl;
	return true;
}
