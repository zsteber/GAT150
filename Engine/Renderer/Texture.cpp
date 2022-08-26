#include "Texture.h"
#include "Renderer.h"
#include "../Core/Logger.h"
#include <SDL.h>
#include <SDL_image.h>

namespace neu
{
	Texture::~Texture()
	{
		if (texture != NULL) SDL_DestroyTexture(texture);
	}

	bool Texture::Create(std::string filename, ...) 
	{
		va_list args;
		va_start(args, filename);
		Renderer& renderer = va_arg(args, Renderer);
		va_end(args);

		return Create(renderer, filename);
	}

	bool Texture::CreateFromSurface(SDL_Surface* surface, Renderer& renderer)
	{
		if (texture) SDL_DestroyTexture(texture);

		texture = SDL_CreateTextureFromSurface(renderer.GetRenderer(), surface);
		SDL_FreeSurface(surface);

		if (texture == nullptr)
		{
			LOG(SDL_GetError());
			return false;
		}
		return true;
	}

	bool Texture::Create(Renderer& renderer, const std::string& filename)
	{
		// Load Surface
		SDL_Surface* surface = IMG_Load(filename.c_str());
		if (surface == nullptr) LOG(SDL_GetError());

		// Create Texture
		texture = SDL_CreateTextureFromSurface(renderer.GetRenderer(), surface);
		if (texture == nullptr)
		{
			LOG(SDL_GetError());
			SDL_FreeSurface(surface);
			return false;
		}

		return true;
	}

	neu::Vector2 Texture::GetSize() const
	{
		SDL_Point point;
		SDL_QueryTexture(texture, nullptr, nullptr, &point.x, &point.y);

		return Vector2{ point.x, point.y };
	}
}