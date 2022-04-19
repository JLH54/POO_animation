#pragma once
#include <vector>
#include <math.h>

struct SDL_Renderer;

class GameObject
{
protected:
	int m_X = 0;
	int m_Y = 0;
	SDL_Renderer* graphics;
public:
	void SetPosition(int x, int y);
	void GetPosition(int* x, int* y);
	void Translate(int dx, int dy);

	virtual void Load(SDL_Renderer* graphics);
	virtual void Draw(SDL_Renderer* graphics);
	virtual void Update(float dt);
};
