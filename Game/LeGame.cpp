#include "LeGame.h"
#include "Engine.h"

namespace neu
{
	void LeGame::Initialize()
	{
		m_scene = std::make_unique<Scene>();

		rapidjson::Document document;
		std::vector<std::string> sceneNames = { "scenes/prefabs.txt", "scenes/tilemap.txt", "scenes/level.txt" };

		for (auto sceneName : sceneNames)
		{
			bool success = json::Load(sceneName, document);
			if (!success)
			{
				LOG("error could not load scene %s", sceneName.c_str());
				continue;
			}

			m_scene->Read(document);
		}
		m_scene->Initialize();



		g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&LeGame::OnAddPoints, this, std::placeholders::_1));
	}

	void LeGame::Shutdown()
	{
		m_scene->RemoveAll();
	}

	void LeGame::Update()
	{
		switch (m_gameState)
		{
		case gameState::titleScreen:
			// m_scene->GetActorFromName("Title")->SetActive(true);
			m_lives = 3;

			if (g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Press)
			{
				m_scene->GetActorFromName("Title")->SetActive(false);

				m_gameState = gameState::startLevel;
			}

			break;

		case gameState::startLevel:
			for (int i = 0; i < 10; i++)
			{
				auto actor = Factory::Instance().Create<Actor>("Coin");
				actor->m_transform.position = { randomf(0, 800), 100.0f };
				actor->Initialize();

				m_scene->Add(std::move(actor));
			}
			m_gameState = gameState::game;
			break;

		case gameState::game:
			break;

		case gameState::playerDead:
			m_stateTimer -= timer.deltaTime;
			if (m_stateTimer <= 0)
			{
				m_gameState = (m_lives > 0) ? gameState::startLevel : gameState::gameOver;
			}
			break;

		case gameState::gameOver:
			break;

		default:
			break;
		}

		m_scene->Update();
	}

	void LeGame::Draw(Renderer& renderer)
	{
		m_scene->Draw(renderer);
	}

	void LeGame::OnAddPoints(const Event& event)
	{
		AddPoints(std::get<int>(event.data));

		std::cout << event.name << std::endl;
		std::cout << GetScore() << std::endl;
	}

	void LeGame::OnPlayerDead(const Event& event)
	{
		m_gameState = gameState::playerDead;
		m_lives--;
		m_stateTimer = 3;
	}
}