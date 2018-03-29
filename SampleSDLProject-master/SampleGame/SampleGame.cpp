// SampleGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Engine.h>
#include "MainScene.h"
#include "SecondScene.h"

int main(int argc, char* args[])
{
	
	core::Engine e(new MainScene, new SecondScene);
	if (e.init() == 0) {
		e.run();
	}
    return 0;
}

