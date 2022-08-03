#pragma once
#include "Game.h"


class SpaceShooter : public neu::Game
	{
	public:
		SpaceShooter() = default;
		~SpaceShooter() = default;

	// Inherited via Game
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(neu::Renderer& renderer) override;

	private:
		float m_spawnTimer = 0;
};
