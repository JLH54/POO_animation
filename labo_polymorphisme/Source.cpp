#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "sprite.h"
#include "Game.h"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_  HINSTANCE, _In_ LPSTR, _In_ int)
{
	srand((unsigned int)time(NULL));

	Game theGame;
	if (theGame.Init("Demo", 600, 800))
	{
		Sprite sp1("assets/env.png");

		sp1.SetAlpha(255);
		sp1.SetColor(255, 255, 255);
		sp1.SetSize(128, 128);
		sp1.SetPosition(100, 100);
		//sp1.SetSource(89, 32, 32);
		theGame.Add(&sp1);


		theGame.Start();
	}

	return 0;
}