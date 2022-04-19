#include "GameObject.h"

void GameObject::SetPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
}

void GameObject::GetPosition(int* x, int* y)
{
    *x = m_X;
    *y = m_Y;
}

void GameObject::Translate(int dx, int dy)
{
    m_X += dx;
    m_Y += dy;
}

void GameObject::Load(SDL_Renderer* graphics)
{

}

void GameObject::Draw(SDL_Renderer* graphics)
{

}

void GameObject::Update(float dt)
{

}
