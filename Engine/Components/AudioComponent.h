#pragma once
#include "../Framework/Component.h"

namespace neu
{
	class AudioComponent : public Component
	{
	public:

		AudioComponent() = default;
		void Update() override;

		CLASS_DECLARATION(AudioComponent);

		void Play();
		void Stop();

		std::string soundName;
		float volume{ 1 };
		float pitch{ 1 };
		bool playOnAwake{ false };
		bool loop{ false };

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	};
}