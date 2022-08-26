#pragma once
#include "../ThirdParty/fmod/core/inc/fmod.hpp"

namespace FMOD
{
	class FMOD::Channel;
}

namespace neu
{
	class AudioChannel
	{
	public:
		AudioChannel() {}
		AudioChannel(FMOD::Channel* channel) { m_channel = channel; }// !! set m_channel 

		bool IsPlaying();
		void Stop();

		void SetPitch(float pitch);
		float GetPitch();

		void SetVolume(float volume);
		float GetVolume();

	private:
		FMOD::Channel* m_channel = nullptr;
	};
}