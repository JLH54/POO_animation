#include "Circle.h"
#include <SDL.h>

void Circle::SetRadius(int radius)
{
    m_Radius = radius;
}

int Circle::GetRadius()
{
    return m_Radius;
}

void Circle::SetColor(unsigned char r, unsigned char g, unsigned char b)
{
	m_Red = r;
	m_Green = g;
	m_Blue = b;
}

void Circle::Draw(SDL_Renderer* graphics)
{
	int tx = m_X;
	int ty = m_Y;
	float angle = 0.0f;

	SDL_SetRenderDrawColor(graphics, m_Red, m_Green, m_Blue, 255);

	while (angle < 6.3f)
	{
		tx = static_cast<int>(m_X + m_Radius * cos(angle));
		ty = static_cast<int>(m_Y + m_Radius * sin(angle));
		SDL_RenderDrawPoint(graphics, tx, ty);
		angle += 0.01f;
	}
}

void Circle::Update(float dt)
{

}
