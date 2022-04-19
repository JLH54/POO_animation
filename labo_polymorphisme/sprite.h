#pragma once
#include "Rectangle.h"
#include <string>

struct SDL_Texture;

class Sprite : public Rectangle
{
public:
	Sprite(const std::string& filename);
	virtual void Load();
	virtual void Draw();
	inline double GetAngle() { return m_Angle;}
	inline void SetAngle(double angle) { m_Angle = angle;}
	inline void SetAlpha(int alpha) { m_Alpha = alpha; }
	void SetSource(int x, int y, int w, int h);
protected:
	void SetSource(int index, int cellWidth, int cellHeight);
private:
	SDL_Texture* m_Texture;
	std::string m_Filename;
	double m_Angle;
	int m_Alpha;

	int m_SrcX;
	int m_SrcY;
	int m_SrcW;
	int m_SrcH;
};

