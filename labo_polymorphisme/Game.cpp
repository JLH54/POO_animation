#include "Game.h"
#include <SDL.h>
#include <Windows.h>
#include <time.h>
#include "GameObject.h"

bool Game::Init(const std::string& title, int width, int heigth)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log("Error : %s\n", SDL_GetError());
		return false;
	}

	if (CreateGameWindow(title, width, heigth))
	{
		if (CreateRenderer())
		{
			m_Running = true;
			return true;
		}
	}

	return false;
}

void Game::Start()
{
	const unsigned int FPS = 60;
	const unsigned int FRAME_TARGET_TIME = 1000 / FPS;
	
	LoadObjects();

	clock_t last = clock();
	while (m_Running)
	{
		const clock_t start = clock();
		float dt = (start - last) * 0.001f;
		ProcessInput();
		UpdateLogic(dt);

		SDL_SetRenderDrawColor(m_Graphics, 64, 64, 64, 255);
		SDL_RenderClear(m_Graphics);

		RenderFrame();
		
		SDL_RenderPresent(m_Graphics);
		
		const clock_t end = clock();
		int rest = start + FRAME_TARGET_TIME - end;
		if (rest > 0)
		{
			Sleep(rest);
		}
		last = start;
	}

	Close();
}

bool Game::CreateGameWindow(const std::string& title, int width, int heigth)
{
	m_Window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width, heigth,
		SDL_WINDOW_UTILITY
	);

	if (m_Window == nullptr)
	{
		SDL_Log("Error : %s\n", SDL_GetError());
		return false;
	}

	return true;
}

bool Game::CreateRenderer()
{
	m_Graphics = SDL_CreateRenderer(
		m_Window,
		0,
		SDL_RENDERER_ACCELERATED
	);

	if (m_Graphics == nullptr)
	{
		SDL_Log("Error : %s\n", SDL_GetError());
		return false;
	}
	return true;
}

void Game::Close()
{
	SDL_DestroyRenderer(m_Graphics);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

void Game::ProcessInput()
{
	SDL_Event events;
	
	while (SDL_PollEvent(&events) > 0)
	{
		switch (events.type)
		{
		case SDL_QUIT:
			m_Running = false;
			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			m_Keyboard = SDL_GetKeyboardState(nullptr);
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_MouState[0] = true;
				break;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_MouState[0] = false;
				break;
			}
			break;
		case SDL_MOUSEMOTION:
			m_MouseX = events.motion.x;
			m_MouseY = events.motion.y;
			break;
		}
	}
}

void Game::LoadObjects()
{
	for (GameObject* o : m_World)
	{
		o->Load(m_Graphics);
	}
}

void Game::Add(GameObject* object)
{
	m_World.push_back(object);
}

void Game::UpdateLogic(float dt)
{
	for (GameObject* o : m_World)
	{
		o->Update(dt);
	}
}

void Game::RenderFrame()
{
	for (GameObject* o : m_World)
	{
		o->Load(m_Graphics);
	}
}