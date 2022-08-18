#include "Engine.h"
#include <iostream>
#include <cassert>


using namespace std;


int main()
{

	neu::InitializeMemory();
	neu::SetFilePath("../Assets");

	rapidjson::Document document;
	bool success = neu::json::Load("level.txt", document);
	//assert(success);

	
	// create systems
	neu::g_renderer.Initialize();
	neu::g_inputSystem.Initialize();
	neu::g_audioSystem.Initialize();

	// create window
	neu::g_renderer.CreateWindow("Chicken Pot Pie", 800, 600);
	neu::g_renderer.SetClearColor(neu::Color{ 0, 0, 0, 255 });


	//create actors
	neu::Scene scene;

	std::unique_ptr<neu::Actor> actor = std::make_unique<neu::Actor>();
	std::unique_ptr<neu::PlayerComponent> pcomponent = std::make_unique<neu::PlayerComponent>();
	actor->AddComponent(std::move(pcomponent));

	scene.Add(std::move(actor));
	scene.Read(document);

	float angle = 0;

	bool quit = false;
	while (!quit)
	{
		// update
		neu::g_inputSystem.Update();
		neu::g_audioSystem.Update();
		neu::timer.Tick();

		if (neu::g_inputSystem.GetKeyState(neu::key_escape)) quit = true;

		angle += 180.0f * neu::timer.deltaTime;
		scene.Update();

		// render
		neu::g_renderer.BeginFrame();
		scene.Draw(neu::g_renderer);

		scene.Update();
		scene.Draw(neu::g_renderer);


		neu::g_renderer.EndFrame();
	}

	neu::g_audioSystem.Shutdown();
	neu::g_inputSystem.Shutdown();
	neu::g_renderer.ShutDown();
}
