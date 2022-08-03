#pragma once
#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"

#include "FrameWork/Scene.h"
#include "FrameWork/Game.h"

#include "Audio/AudioSystem.h"


namespace neu
{
	extern InputSystem g_inputSystem;
	extern Renderer g_renderer;
	extern Time timer;
	extern AudioSystem g_audioSystem;
}