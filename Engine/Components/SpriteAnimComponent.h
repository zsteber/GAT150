#pragma once
#include "RenderComponent.h"
#include "Math/Rect.h"

namespace neu
{
	class Texture;

	class SpriteAnimComponent : public RenderComponent
	{
	public:
		CLASS_DECLARATION(SpriteAnimComponent);

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		virtual void Initialize() override {}

		bool Write(const rapidjson::Value& value) const override;
		bool Read(const rapidjson::Value& value) override;

		Rect& GetSource() override;

		float fps = 0;
		int num_columns = 0;
		int num_rows = 0;

		int start_frame = 0;
		int end_frame = 0;

		int frame = 0;
		float frameTimer = 0;

		Rect source;
		std::shared_ptr<Texture> m_texture;
	};
}