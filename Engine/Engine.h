#pragma once

#include "JSON.h"

#include "Math/Random.h"
#include "Math/MathUtils.h"

#include "Core/Memory.h"
#include "Core//File.h"
#include "Core/Time.h"
#include "Core/Logger.h"

#include "Renderer/Renderer.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Renderer/Texture.h"
#include "Renderer/Model.h"

#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Resource/ResourceManager.h"
#include "Physics/PhysicsSystem.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Framework/Factory.h"
#include "Framework/Singleton.h"
#include "FrameWork/Event.h"
#include "FrameWork/EventManager.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/AudioComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/RBPhysicsComponent.h"
#include "Components/ModelComponent.h"
#include "Components/SpriteAnimComponent.h"
#include "Components/TilemapComponent.h"
#include "Components/EnemyComponent.h"
#include "Components/CharacterComponent.h"

#include <memory>

namespace neu
{
	extern InputSystem g_inputSystem;
	extern Renderer g_renderer;
	extern Time timer;
	extern AudioSystem g_audioSystem;
	extern ResourceManager g_resources;
	extern PhysicsSystem g_physicsSystem;
	extern EventManager g_eventManager;

	class Engine : public Singleton<Engine>
	{
	public:
		void Register();

	};
}