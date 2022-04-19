#pragma once
#include "GameObject.h"
#include "SDL_image.h"
class Rectangle : public GameObject
{
protected:
	int m_Width = 10;
	int m_Height = 10;
	unsigned char m_Red = 0;
	unsigned char m_Green = 0;
	unsigned char m_Blue = 0;

public:
	void SetSize(int width, int height);
	void GetSize(int* width, int* height);
	void SetColor(unsigned char r, unsigned char g, unsigned char b);

	virtual void Draw(SDL_Renderer* graphics) override;
	virtual void Update(float dt) override;
};

