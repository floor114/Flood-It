#include "Ground.h"
#include "Menu.h"
#include "Game.h"
#include "ChooseLevel.h"
#include "Records.h"
#include "Finish.h"
#include "ReadRecords.h"
#include "Keyboard.h"
#ifndef _RUN_H_
#define _RUN_H_
class Run
{
private:
	bool on;
	Menu menu;
	Game game;
	ChooseLevel choose;
	Records record;
	Finish finish;
	ReadRecord readrecord;
	Keyboard keyboard;
public:
	void inGame(){
		setOn(true);
		menu.create();	
		int stp,lvl;
		while (on)
		{			
			if (game.getFinish()) {
				SDL_Delay(200);
				if (readrecord.getlist(game.getGtype()).back().getStep() > game.getStep() || readrecord.getNumbOfRec()<10){
					keyboard.create();
					stp = game.getStep();
					lvl = game.getGtype();
					game.destroy();
				}
				else{
					finish.create(game.getGtype(), game.getStep());
					readrecord.saveRecords(game.getGtype(), keyboard.getName(), game.getStep());
					readrecord.destroy();
					game.destroy();
				}
			}			
			SDL_WaitEvent(&event);
			switch (event.type)
			{
			case SDL_QUIT:
			{
				setOn(false);
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				if (event.button.button = SDL_BUTTON_LEFT)
				{
					int x = event.button.x, y = event.button.y;
					if (keyboard.getON()){
						keyboard.check(x, y);
						if (!keyboard.getInputing()){
							finish.create(lvl, stp);
							readrecord.saveRecords(lvl, keyboard.getName(), stp);
							keyboard.clearStr();
						}
					}
					else
					if (menu.getOn()){
						if (menu.getButton(0).check(x, y)){
							menu.getButton(0).pressed();
							menu.destroy();
							choose.create();
						}
						if (menu.getButton(1).check(x, y)){
							menu.getButton(1).pressed();
							menu.destroy();
							record.create(1);
						}
						if (menu.getButton(2).check(x, y)){
							menu.getButton(2).pressed();
							menu.destroy();
							setOn(false);
						}
						if (menu.getButton(3).check(x, y)){
							menu.getButton(3).pressed();
							keyboard.create();

						}
					}					
					else
						if (choose.getON()){
							if (choose.getButton(0).check(x, y)){
								choose.getButton(0).pressed();
								choose.destroy();								
								menu.create();
							}
							if (choose.getButton(1).check(x, y)){
								SDL_Delay(100);
								choose.destroy();
								readrecord.readRecord(1);
								game.create(1,readrecord.getRecord());
							}
							if (choose.getButton(2).check(x, y)){
								SDL_Delay(100);
								readrecord.readRecord(2);
								choose.destroy();
								game.create(2, readrecord.getRecord());
							}
							if (choose.getButton(3).check(x, y)){
								SDL_Delay(100);
								readrecord.readRecord(3);
								choose.destroy();
								game.create(3, readrecord.getRecord());
							}

						}
						else
							if (game.getON()){
								game.checkMap(x, y);
								if (game.getButton(0).check(x, y)){
									game.getButton(0).pressed();
									game.newGame(true);
								}
								if (game.getButton(1).check(x, y)){
									game.getButton(1).pressed();
									game.refresh(true);
								}
								if (game.getButton(2).check(x, y)){
									game.setON(false);
									game.getButton(2).pressed();
									game.destroy();
									menu.create();
								}
							}
							else
								if (record.getON()){

									if (record.getleftbar().check(x, y)==1){
										record.drawRecords(1);
									}	
									if (record.getleftbar().check(x, y) == 2){
										record.drawRecords(2);
									}
									if (record.getleftbar().check(x, y) == 3){
										record.drawRecords(3);
									}										

									
									if (record.getButton().check(x, y)){
										record.getButton().pressed();
										record.destroy();
										menu.create();
									}

								}
								else
									if (finish.getOn()){
										if (finish.getButton(0).check(x, y)){
											finish.getButton(0).pressed();
											finish.destroy();
											choose.create();
										}
										if (finish.getButton(1).check(x, y)){
											finish.getButton(1).pressed();											
											record.create(finish.getLevel());
											finish.destroy();
										}
										if (finish.getButton(2).check(x, y)){
											finish.getButton(2).pressed();
											finish.destroy();
											menu.create();
										}
									}					
					break;
				}
				break;
			}
			case SDL_KEYDOWN:
			{						
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					{
						if (menu.getOn())
							setOn(false);
						break;
					}
					case SDLK_q:
					{
						if (game.getON())
						{
							game.addColor(COLOR_BLUE);
							game.drawStep();
							break;
						}
						break;
					}
					case SDLK_w:
					{
						if (game.getON())
						{
							game.addColor(COLOR_GREEN);
							game.drawStep();
							break;
						}
						break;
					}
					case SDLK_e:
					{
						if (game.getON())
						{
							game.addColor(COLOR_ORANGE);
							game.drawStep();
							break;
						}
						break;
					}
					case SDLK_a:
					{
						if (game.getON())
						{
							game.addColor(COLOR_RED);
							game.drawStep();
							break;
						}
						break;
					}
					case SDLK_s:
					{
						if (game.getON())
						{
							game.addColor(COLOR_VIOLETT);
							game.drawStep();
							break;
						}
						break;
					}
					case SDLK_d:
					{
						if (game.getON())
						{
							game.addColor(COLOR_YELLOW);
							game.drawStep();
							break;
						}
						break;
					}
					case SDLK_F2:
					{
						if (game.getON())
						{
							game.newGame(true);
							break;
						}
						break;
					}
				}
				break;
			}
			}
		}
	}
	void setOn(bool on){
		this->on = on;
	}
	bool getOn(){
		return on;
	}
};
#endif
