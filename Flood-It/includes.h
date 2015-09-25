#ifndef _INCLUDES_H_
#define _INCLUDES_H_
#include <iostream>
#include <SDL.h>
#include <SDL_TTF.h>
#include <SDL_image.h>
#include <cstdlib>
#include <ctime>
#include <clocale>

#include <list>
#include <fstream>
#include <string>

#define WINDOW_WIDTH 590
#define WINDOW_HEIGHT 450
#define COLOR_BLUE 0
#define COLOR_GREEN 1
#define COLOR_ORANGE 2
#define COLOR_RED 3
#define COLOR_VIOLETT 4
#define COLOR_YELLOW 5

SDL_Surface * screen;
SDL_Event event;
SDL_Surface  *background;
#endif