#pragma once
#include "../Framework/Component.h"

namespace neu
{
	class AudioComponent : public Component
	{
	public:

		AudioComponent() = default;
		void Update() override;

		void Play();
		void Stop();

		std::string soundName;
		float volume{ 1 };
		float pitch{ 1 };
		bool playOnAwake{ false };
		bool loop{ false };
	};
}