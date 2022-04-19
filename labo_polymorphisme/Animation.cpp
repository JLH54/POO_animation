#include "Animation.h"

void Animation::Update(float dt)
{
	m_Elapsed += dt;
	if (m_Elapsed >= m_Delay)
	{
		//change frame
		m_Elapsed = 0.0f;
	}
}