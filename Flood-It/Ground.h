#include "includes.h"
#ifndef _GROUND_H_
#define _GROUND_H_
class Ground
{
public:
	int setImg(char filename[40], int bx, int by, int bw, int bh){
		SDL_Surface *img;
		img = IMG_Load(filename);
		if (!img)
		{
			IMG_GetError();
			return -1;
		}
		SDL_Rect desc;
		desc.x = bx;
		desc.y = by;
		SDL_Rect src;
		src.x = 0;
		src.y = 0;
		src.w = bw;
		src.h = bh;
		SDL_BlitSurface(img, &src, screen, &desc);
		SDL_Flip(screen);
		SDL_FreeSurface(img);
		return 0;
	}

	int CreateBackground(char filename[20]){
		if (background)
		{
			SDL_FreeSurface(background);
		}
		background = IMG_Load(filename);
		if (!background)
		{
			IMG_GetError();
			return -1;
		}
		SDL_BlitSurface(background, NULL, screen, NULL);
		SDL_Flip(screen);
		return 1;
	}

	void ClearWindow(int x, int y, int w, int h, int r, int g, int b){
		SDL_Rect desc;
		desc.x = x;
		desc.y = y;
		desc.w = w;
		desc.h = h;
		SDL_FillRect(screen, &desc, SDL_MapRGB(screen->format, r, g, b));
		SDL_Flip(screen);
	}

	int ChangeSurface(SDL_Surface* Dest, SDL_Surface* Src, int X, int Y, int X2, int Y2, int W, int H){
		if (Dest == NULL || Src == NULL)
		{
			SDL_GetError();
			return -1;
		}
		SDL_Rect DestArea;
		DestArea.x = X;
		DestArea.y = Y;

		SDL_Rect SrcArea;
		SrcArea.x = X2;
		SrcArea.y = Y2;
		SrcArea.w = W;
		SrcArea.h = H;

		SDL_BlitSurface(Src, &SrcArea, Dest, &DestArea);
		SDL_Flip(screen);
		return 1;
	}

	int CopySurface(SDL_Surface *image, int x, int y){
		if (!screen){
			SDL_Rect r = { x, y };
			SDL_BlitSurface(screen, &r, image, 0);
		}

		return 1;
	}

	void WriteText(int x, int y, char text[100], int sz, int r, int g, int b){
		SDL_Color clr;
		clr.r = r;
		clr.g = g;
		clr.b = b;
		TTF_Font * fnt = TTF_OpenFont("fonts/courier.ttf", sz);
		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		SDL_Surface * sText = TTF_RenderText_Blended(fnt, text, clr);
		SDL_BlitSurface(sText, NULL, screen, &dest);
		SDL_FreeSurface(sText);
		TTF_CloseFont(fnt);
		SDL_Flip(screen);
	}

};
#endif
