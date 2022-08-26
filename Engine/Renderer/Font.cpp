#include "Font.h"
#include <SDL_ttf.h>
#include "Renderer.h"
#include <Engine.cpp>

neu::Font::Font(const std::string& filename, int fontSize)
{
	Load(filename, fontSize);
}

neu::Font::~Font()
{
	if (m_ttfFont != NULL)
	{
		TTF_CloseFont(m_ttfFont);
	}
}

bool neu::Font::Create(std::string filename, ...)
{
	va_list args;
	va_start(args, filename);
	int fontSize = va_arg(args, int);
	va_end(args);
	return Create(filename, fontSize);
}

bool neu::Font::Create(const std::string& filename, int& fontsize)
{
	if (!Load(filename, fontsize))
	{
		return false;
	}
	return true;
}
namespace neu
{

	SDL_Surface* Font::CreateSurface(const std::string& text, const Color& color)
	{
		SDL_Color c = *((SDL_Color*)(&color));
		SDL_Surface* surface = TTF_RenderText_Solid(m_ttfFont, text.c_str(), c);

		if (!surface)
		{
			LOG(SDL_GetError());
		}

		return surface;
	}
}

bool neu::Font::Load(const std::string& filename, int fontSize)
{
	m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);

	if (m_ttfFont == nullptr)
	{
		return false;
	}

	return true;
}