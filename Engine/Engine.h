#pragma once

#include "JSON.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "FrameWork/GameObject.h"
#include "FrameWork/Factory.h"

#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"

#include "FrameWork/Singleton.h"

#include "Resource/ResourceManager.h"

#include "FrameWork/Scene.h"
#include "FrameWork/Game.h"

#include "Components/PlayerComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/ModelComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/SpriteAnimComponent.h"


#include "Audio/AudioSystem.h"


namespace neu
{
	extern InputSystem g_inputSystem;
	extern Renderer g_renderer;
	extern Time timer;
	extern AudioSystem g_audioSystem;
	extern ResourceManager g_resources;

	class Engine : public Singleton<Engine>
	{
	public:
		void Register();

	};
}