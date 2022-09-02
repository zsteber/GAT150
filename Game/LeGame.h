#pragma once
#include "Framework/Game.h"
#include "Framework/Event.h"



class LeGame : public neu::Game, public neu::INotify
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
	virtual void Draw(neu::Renderer& renderer) override;

	virtual void OnNotify(const neu::Event& event) override;
	void OnAddPoints(const neu::Event& event);
	void OnPlayerDead(const neu::Event& event);

private:
	gameState m_gameState = gameState::titleScreen;
	float m_stateTimer = 0;
	int m_lives = 3;
};