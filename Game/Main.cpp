#include "Engine.h"
#include <Renderer/Text.h>
#include <Renderer/Font.h>


using namespace std;


int main()
{
	neu::InitializeMemory();
	neu::SetFilePath("../Assets");

	// create systems
	neu::g_renderer.Initialize();
	neu::g_inputSystem.Initialize();
	neu::g_audioSystem.Initialize();

	// create window
	neu::g_renderer.CreateWindow("Chicken Pot Pie", 800, 600);
	neu::g_renderer.SetClearColor(neu::Color{ 0, 0, 0, 255 });

	neu::Scene scene;


	bool quit = false;

	while (!quit)
	{
		// update
		neu::g_inputSystem.Update();
		neu::g_audioSystem.Update();
		neu::timer.Tick();


		if (neu::g_inputSystem.GetKeyState(neu::key_escape)) quit = true;


		// render
		neu::g_renderer.BeginFrame();

		

		scene.Update();

		scene.Draw(neu::g_renderer);


		neu::g_renderer.EndFrame();
	}

	neu::g_audioSystem.Shutdown();
	neu::g_inputSystem.Shutdown();
	neu::g_renderer.ShutDown();
}
