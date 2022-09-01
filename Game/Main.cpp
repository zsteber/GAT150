#include "Engine.h"
#include "LeGame.h"
#include <iostream>

using namespace std;


int main()
{
	neu::InitializeMemory();

	neu::SetFilePath("../Assets");

	// initialize systems
	neu::g_renderer.Initialize();
	neu::g_inputSystem.Initialize();
	neu::g_audioSystem.Initialize();
	neu::g_resources.Initialize();
	neu::g_physicsSystem.Initialize();
	neu::g_eventManager.Initialize();
	neu::Engine::Instance().Register();

	// create window
	neu::g_renderer.CreateWindow("LeGame", 800, 600);
	neu::g_renderer.SetClearColor(neu::Color{ 20, 20, 20, 0 });

	// create scene
	unique_ptr<neu::LeGame> game = make_unique<neu::LeGame>();
	game->Initialize();

	bool quit = false;
	while (!quit)
	{

		//update (engine)
		neu::timer.Tick();
		neu::g_inputSystem.Update();
		neu::g_audioSystem.Update();
		neu::g_physicsSystem.Update();
		neu::g_eventManager.Update();

		if (neu::g_inputSystem.GetKeyDown(neu::key_escape)) { quit = true; }

		// update Scene
		game->Update();

		// renderer
		neu::g_renderer.BeginFrame();

		game->Draw(neu::g_renderer);

		neu::g_renderer.EndFrame();
	}

	game->Shutdown();
	game.reset();

	neu::Factory::Instance().Shutdown();

	neu::g_physicsSystem.Shutdown();
	neu::g_resources.Shutdown();
	neu::g_inputSystem.Shutdown();
	neu::g_audioSystem.Shutdown();
	neu::g_renderer.ShutDown();
	neu::g_eventManager.Shutdown();
}
