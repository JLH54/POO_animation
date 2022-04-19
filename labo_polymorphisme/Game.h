#pragma once
#include <string>
#include <vector>

struct SDL_Window;
struct SDL_Renderer;
class GameObject;

class Game
{
public:
	bool Init(const std::string& title, int width, int heigth);
	void Start();
	void Add(GameObject* object);

private:
	bool CreateGameWindow(const std::string& title, int width, int heigth);
	bool CreateRenderer();
	void Close();
	void ProcessInput();
	void UpdateLogic(float dt);
	void RenderFrame();
	void LoadObjects();

private:
	std::vector<GameObject*> m_World;
	SDL_Window* m_Window;
	SDL_Renderer* m_Graphics;
	bool m_Running = false;
	const unsigned char* m_Keyboard = nullptr;
	bool m_MouState[3] = { false,false,false };
	int m_MouseX = 0;
	int m_MouseY = 0;
};
