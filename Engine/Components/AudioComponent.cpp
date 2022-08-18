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
	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}
	bool AudioComponent::Read(const rapidjson::Value& value)
	{
		return true;
	}
}