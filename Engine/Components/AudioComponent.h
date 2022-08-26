#pragma once
#include "Framework/Component.h"
#include "Audio/AudioChannel.h"

namespace neu
{
	class AudioComponent : public Component
	{
	public:

		AudioComponent() = default;
		~AudioComponent();

		virtual void Initialize() override;
		void Update() override;

		void Play();
		void Stop();

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		AudioChannel m_channel;
		std::string m_soundName;
		float m_volume{ 1 };
		float m_pitch{ 1 };
		bool m_playOnAwake{ false };
		bool m_loop{ false };
	};
}