#ifndef _GAME_H_
#define _GAME_H_
class Game : public Ground
{
private:
	bool on, finish;
	SDL_Surface *block[6];
	int map[28][28], tmpm[28][28], step, startclr, maps, h, gtype;
	Button button[3];
	public:
		void create(int gType,int record){
			setMaps(gType);
			setGType(gType);
			setON(true);
			CreateBackground("images/Background.png");
			if (gtype == 1){
				setH(30);
				WriteText(498 - 10, 215, "1", 96, 247, 199, 8);
			}
			else
				if (gtype == 2){
					setH(20);
					WriteText(498 - 10, 215, "2", 96, 247, 199, 8);
				}
				else
					if (gtype == 3){
						setH(15);
						WriteText(498 - 10, 215, "3", 96, 247, 199, 8);
					}
			setBlock();
			button[0].create(453, 7, 127, 43, "images/NGbutton0.png", 482, 22 - 3, 24, "Reset", 255, 255, 255);
			button[1].create(453, 347, 127, 43, "images/NGbutton2.png", 482, 361 - 2, 24, "Again", 255, 255, 255);
			button[2].create(453, 400, 127, 43, "images/NGbutton1.png", 488, 414 - 2, 24, "Menu", 255, 255, 255);
			WriteText(457, 180, "Level:", 36, 255, 255, 255);
			WriteText(457, 70, "Steps:", 36, 255, 255, 255);
			WriteText(467, 297, "Record:", 24, 136, 136, 136);
			char tmpch[100];
			for (int i = 0; i < 100; i++)
				tmpch[i] = 0;			
			sprintf_s(tmpch, "%d", record);
			WriteText(504, 318,tmpch, 24, 136, 136, 136);

			ganerationMap();
			drawMap();
			step = 0;
			drawStep();
		}

		void destroy(){
			setON(false);
			setFinish(false);
			for (int i = 0; i < 6; i++)
				SDL_FreeSurface(block[i]);
			for (int i = 0; i < 3; i++)
				button[i].destroy();
		}

		void checkMap(int x, int y){
			if (x - 15 < h * maps && y - 15 < h * maps)
			{
				addColor(getMap((x - 15) / h, (y - 15) / h));
				drawStep();
			}
		}

		int setImg(SDL_Surface * img, int x, int y){
			SDL_Rect desc;
			desc.x = x;
			desc.y = y;
			SDL_Rect src;
			src.x = 0;
			src.y = 0;
			src.w = 30;
			src.h = 30;
			SDL_BlitSurface(img, &src, screen, &desc);
			return 0;
		}

		int setBlock(){
			for (int i = 0; i < 6; i++)
			{
				char path[20];
				for (int j = 0; j < 20; j++)
					path[j] = 0;
				sprintf_s(path, "images/%dBlock%d.bmp", gtype, i);
				block[i] = SDL_LoadBMP(path);
				if (!block[i])
					return -1;
			}
			return 1;
		}

		void ganerationMap(){
			for (int i = 0; i < maps; i++)
				for (int j = 0; j < maps; j++){
					map[i][j] = rand() % 6;
					tmpm[i][j] = map[i][j];
				}
		}

		void refresh(bool type){
			step = 0;

			for (int i = 0; i < maps; i++)
				for (int j = 0; j < maps; j++)
				{
					map[i][j] = tmpm[i][j];
				}

			drawMap();
			if (type)
				drawStep();
		}

		void drawMap(){
			for (int i = 0; i < maps; i++)
				for (int j = 0; j < maps; j++)
					setImg(block[map[i][j]], h * i + 15, h * j + 15);
			SDL_Flip(screen);
		}

		void setColor(int x, int y, int clr){
			map[x][y] = clr;
			setImg(block[map[x][y]], h * x + 15, h * y + 15);
			if (x - 1 >= 0 && map[x - 1][y] == startclr)
			{
				setColor(x - 1, y, clr);
			}
			if (x + 1 < maps && map[x + 1][y] == startclr)
			{
				setColor(x + 1, y, clr);
			}
			if (y - 1 >= 0 && map[x][y - 1] == startclr)
			{
				setColor(x, y - 1, clr);
			}
			if (y + 1 < maps && map[x][y + 1] == startclr)
			{
				setColor(x, y + 1, clr);
			}
		}

		void addColor(int clr){
			if (clr == map[0][0])
				return;
			step++;
			startclr = map[0][0];
			setColor(0, 0, clr);
		}

		bool finishGame(){
			int clr = map[0][0];
			for (int i = 0; i < maps; i++)
				for (int j = 0; j < maps; j++)
					if (map[i][j] != clr)
						return false;
			return true;
		}

		void newGame(bool type){
			step = 0;
			ganerationMap();
			drawMap();
			if (type)
				drawStep();
		}

		void drawStep(){
			char tmpch[100];
			for (int i = 0; i < 100; i++)
				tmpch[i] = 0;
				sprintf_s(tmpch, "%d", step);
			ChangeSurface(screen, background, 453, 104, 453, 104, 127, 58);
			if (step < 10){

				WriteText(498 - 6, 108, tmpch, 72, 49, 154, 222);
			}
			else
				if (step < 100){
					WriteText(480 - 8, 108, tmpch, 72, 49, 154, 222);
				}
				else
					if (step < 1000){
						WriteText(458 - 8, 108, tmpch, 72, 49, 154, 222);
					}
			if (finishGame()){
				setFinish(true);
			}
		}

		void setFinish(bool finish){
			this->finish = finish;
		}
		bool getFinish(){
			return finish;
		}

		int getStep(){
			return step;
		}

		int getGtype(){
			return gtype;
		}

		void setON(bool on){
			this->on = on;
		}
		bool getON(){
			return on;
		}

		void setMaps(int maps){
			if (maps == 1)
				this->maps = 14;
			else
				if (maps == 2)
					this->maps = 21;
				else
					if (maps == 3)
						this->maps = 28;
		}
		int getMaps(){
			return maps;
		}

		void setGType(int gType){
			this->gtype = gType;
		}
		int getGType(){
			return gtype;
		}

		void setH(int h){
			this->h = h;
		}
		int getH(){
			return h;
		}

		Button getButton(int i){
			return this->button[i];
		}

		int getMap(int i, int j){
			return map[i][j];
		}
	};
#endif