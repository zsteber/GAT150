#pragma once
#include "RenderComponent.h"
#include "Math/Rect.h"

namespace neu
{
	class Texture;

	class SpriteComponent : public RenderComponent
	{
	public:
		CLASS_DECLARATION(SpriteComponent);

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		virtual void Initialize() override {}

		bool Write(const rapidjson::Value& value) const;
		bool Read(const rapidjson::Value& value);

		Rect source;
		std::shared_ptr<Texture> m_texture;
	};
}