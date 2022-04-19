#pragma once
#include "sprite.h"

class Animation : public Sprite
{
public:
	virtual void Update(float dt) override;

private:
	int m_FirstIndex;
	int m_CountFram;
	int m_CurrentFrame;
	float m_Delay;

	float m_Elapsed = 0.0f;


};

