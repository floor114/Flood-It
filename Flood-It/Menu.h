#include "Button.h"
#ifndef _MENU_H_
#define _MENU_H_
class Menu :
	public Ground
{
private:
	bool on;
	Button button[4];
public:
	void create(){
		setOn(true);
		CreateBackground("images/Background.png");
		WriteText(156, 57, "Flood-It", 59, 255, 255, 255);
		button[0].create(208, 166, 175, 43, "images/NButton0.png", 208 + 31, 166 + 12, 24, "New Game", 255, 255, 255);
		button[1].create(208, 224, 175, 43, "images/Nbutton1.png", 246, 224 + 12, 24, "Records", 255, 255, 255);
		button[2].create(208, 282, 175, 43, "images/Nbutton2.png", 268, 296, 24, "Exit", 255, 255, 255);
	}

	void destroy(){
		for (int i = 0; i < 3; i++)
			button[i].destroy();
		setOn(false);
	}

	Button getButton(int i){
		return button[i];
	}

	void setOn(bool on){
		this->on = on;
	}
	bool getOn(){
		return on;
	}
};
#endif


