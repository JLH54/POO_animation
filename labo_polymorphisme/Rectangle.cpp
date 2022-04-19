#include "Rectangle.h"
#include <SDL.h>

void Rectangle::SetSize(int width, int height)
{
    m_Width = width;
    m_Height = height;
}

void Rectangle::GetSize(int* width, int* height)
{
    *width = m_Width;
    *height = m_Height;
}

void Rectangle::SetColor(unsigned char r, unsigned char g, unsigned char b)
{
    m_Red = r;
    m_Green = g;
    m_Blue = b;
}

void Rectangle::Draw(SDL_Renderer* graphics)
{
    SDL_Rect rect = { m_X, m_Y, m_Width, m_Height };
    SDL_SetRenderDrawColor(graphics, m_Red, m_Green, m_Blue, 255);
    SDL_RenderDrawRect(graphics, &rect);
}

void Rectangle::Update(float dt)
{

}
