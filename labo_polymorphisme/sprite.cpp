#include "Sprite.h"

Sprite::Sprite(const std::string& filename) :
	m_Texture(nullptr),
	m_Filename(filename),
	m_Angle(0.0)
{

}

void Sprite::Load()
{
	IMG_LoadTexture(graphics, m_Filename.c_str());
	if (m_Texture == nullptr)
	{
		SDL_Log("Error");
	}
}

void Sprite::Draw()
{
	SDL_SetTextureBlendMode(m_Texture, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(m_Texture, m_Alpha);
	SDL_SetTextureColorMod(m_Texture, m_Red, m_Green, m_Blue);

	SDL_Rect dst =
	{
		m_X,
		m_Y,
		m_Width,
		m_Height
	};

	SDL_Rect src =
	{
		0,
		224,
		32,
		32
	};

	SDL_RenderCopyEx(

		graphics, 
		m_Texture,
		nullptr,
		nullptr,
		0.0f,
		nullptr,
		SDL_FLIP_NONE
	);
}

void Sprite::SetSource(int x, int y, int w, int h)
{
	m_SrcX = x;
	m_SrcY = y;
	m_SrcW = w;
	m_SrcH = h;
}

void Sprite::SetSource(int index, int cellWidth, int cellHeight)
{
	int texW, texH;
	SDL_QueryTexture(m_Texture, nullptr, nullptr, &texW, &texH);

	int row = texW / cellWidth;
	int col = texH / cellHeight;

	m_SrcX = (index % row) * cellWidth;
	m_SrcY = (index / row) * cellHeight;
	m_SrcW = cellWidth;
	m_SrcH = cellHeight;
}
