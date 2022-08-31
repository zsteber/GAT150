#include "Engine.h"
#include <iostream>
#include <cassert>

namespace neu
{

	int main() {
		InitializeMemory();
		SetFilePath("../Assets");


		g_renderer.Initialize();
		g_inputSystem.Initialize();
		g_audioSystem.Initialize();
		g_resources.Initialize();
		g_physicsSystem.Initialize();

		Engine::Instance().Register();

		g_renderer.CreateWindow("Game", 800, 600);
		g_renderer.SetClearColor(Color{ 0, 0, 0, 255 });

		Scene scene;

		rapidjson::Document document;
		bool success = json::Load("json.txt", document);
		scene.Read(document);

		std::unique_ptr<Actor> actor = std::make_unique<Actor>();
		std::unique_ptr<PlayerComponent> playerComponent = std::make_unique <PlayerComponent>();
		actor->AddComponent(std::move(playerComponent));

		scene.Add(std::move(actor));
		scene.Read(document);

		float angle = 0;

		bool quit = false;
		while (!quit) {
			g_inputSystem.Update();
			g_audioSystem.Update();
			g_physicsSystem.Update();
			timer.Tick();

			scene.Update();

			g_renderer.BeginFrame();
			scene.Draw(g_renderer);
			scene.Update();
			scene.Draw(g_renderer);

			g_renderer.EndFrame();
		}
		scene.RemoveAll();
		g_audioSystem.Shutdown();
		g_inputSystem.Shutdown();
		g_renderer.ShutDown();
		g_resources.Shutdown();
	}
}