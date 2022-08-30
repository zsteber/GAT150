#pragma once
#include "../Math/Rect.h"
#include "../Framework/Component.h"

namespace neu
{
	class Renderer;

	class RenderComponent : public Component
	{
	public:
		virtual void Draw(Renderer& renderer) = 0;
		virtual Rect& GetSource() { return source; }

	protected:
		Rect source;
	};
}