#pragma once
#include "Framework/Game.h"
#include "Framework/Event.h"


namespace neu
{
	class LeGame : public Game
	{
	public:
		enum class gameState
		{
			titleScreen,
			startLevel,
			game,
			playerDead,
			gameOver
		};

	public:
		virtual void Initialize() override;
		virtual void Shutdown() override;

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		void OnAddPoints(const Event& event);
		void OnPlayerDead(const Event& event);

	private:
		gameState m_gameState = gameState::titleScreen;
		float m_stateTimer = 0;
		int m_lives = 3;
	};
}