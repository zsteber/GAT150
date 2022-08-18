#include "Engine.h"
#include <iostream>
#include <cassert>


using namespace std;


int main()
{

	neu::InitializeMemory();
	neu::SetFilePath("../Assets");

	rapidjson::Document document;
	bool success = neu::json::Load("json.txt", document);
	//assert(success);

	std::string str;
	neu::json::Get(document, "string", str);
	cout << str << std::endl;

	bool b;
	neu::json::Get(document, "boolean", b);
	cout << b << std::endl;

	int i1;
	neu::json::Get(document, "integer1", i1);
	cout << i1 << std::endl;

	int i2;
	neu::json::Get(document, "integer2", i2);
	cout << i2 << std::endl;

	float f;
	neu::json::Get(document, "float", f);
	cout << f << std::endl;

	neu::Vector2 v2;
	neu::json::Get(document, "vector2", v2);
	cout << v2 << std::endl;

	neu::Color color;
	neu::json::Get(document, "color", color);
	cout << color << std::endl;

	// create systems
	neu::g_renderer.Initialize();
	neu::g_inputSystem.Initialize();
	neu::g_audioSystem.Initialize();

	// create window
	neu::g_renderer.CreateWindow("Chicken Pot Pie", 800, 600);
	neu::g_renderer.SetClearColor(neu::Color{ 0, 0, 0, 255 });


	std::shared_ptr<neu::Texture> texture = std::make_shared<neu::Texture>();
	texture->Create(neu::g_renderer, "sf2.png");

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
		neu::g_renderer.Draw(texture, { 200, 200 }, angle, { 2, 2 }, { 0.5f, 0.5f });
		scene.Draw(neu::g_renderer);

		scene.Update();
		scene.Draw(neu::g_renderer);


		neu::g_renderer.EndFrame();
	}

	neu::g_audioSystem.Shutdown();
	neu::g_inputSystem.Shutdown();
	neu::g_renderer.ShutDown();
}
