#include "Actor.h"
#include "../Components/RenderComponent.h"
#include "../Components/PlayerComponent.h"

namespace neu
{
	void neu::Actor::Draw(Renderer& renderer)
	{
		for (auto& component : m_component)
		{
			//component->Update();
			auto renderComponent = dynamic_cast<RenderComponent*>(component.get());
			if (renderComponent)
			{
				renderComponent->Draw(renderer);
			}
		}
	}

	void Actor::AddComponent(std::unique_ptr<Component> component)
	{
		component->m_owner = this;
 
		m_component.push_back(std::move(component));
	}

	void neu::Actor::Update()
	{
		for (auto& component : m_component)
		{
			component->Update();
		}
	}
}