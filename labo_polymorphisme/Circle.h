#pragma once
#include "GameObject.h"

class Circle : public GameObject
{
protected:
	int m_Radius = 5;

	unsigned char m_Red = 0;
	unsigned char m_Green = 0;
	unsigned char m_Blue = 0;

public:
	void SetRadius(int radius);
	int GetRadius();
	void SetColor(unsigned char r, unsigned char g, unsigned char b);

	virtual void Draw(SDL_Renderer* graphics) override;
	virtual void Update(float dt) override;
};

