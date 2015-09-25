#include "Run.h"

int Initialization()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		SDL_GetError();
		return -1;
	}

	if (TTF_Init() < 0){
		TTF_GetError();
		return -1;
	}

	return 0;
}

int CreateWindow(int w, int h)
{
	screen = SDL_SetVideoMode(w, h, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (!screen)
	{
		IMG_GetError();
		return -1;
	}
	SDL_Surface *g_icon;
	g_icon = IMG_Load("images/icon.ico");
	if (!g_icon)
	{
		IMG_GetError();
		return -1;
	}
	SDL_WM_SetIcon(g_icon, NULL);
	SDL_WM_SetCaption("Flood-It", NULL);
	return 0;
}

Run run;

int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "");
	srand(time(NULL));

	Initialization();
	CreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
	run.inGame();

	SDL_FreeSurface(screen);
	SDL_Quit();
	return 0;
}