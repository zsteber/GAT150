#include "AudioComponent.h"
#include "../Engine.h"

namespace neu
{
	void AudioComponent::Update()
	{

	}

	void AudioComponent::Play()
	{
		g_audioSystem.PlayAudio(soundName, loop);
	}

	void AudioComponent::Stop()
	{

	}
}