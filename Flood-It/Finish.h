#ifndef _FINISH_H
#define _FINISH_H
class Finish : public Ground
{
private:
	Button button[3];
	int level;
	bool on;
public:
	void create(int level, int step){
		setLevel(level);		
		setOn(true);
		CreateBackground("images/Background.png");
		char tmpch[100];
		sprintf_s(tmpch, "%d", getLevel());
		WriteText(150, 107, "Level:", 80, 255, 255, 255);
		WriteText(427, 107, tmpch, 80, 247, 199, 8);
		WriteText(150, 180, "Steps:", 60, 255, 255, 255);
		for (int i = 0; i < 100; i++)
			tmpch[i] = 0;
		sprintf_s(tmpch, "%d", step);
		WriteText(360, 180, tmpch, 60, 49, 154, 222);
		button[0].create(123, 282, 175, 43, "images/Nbutton0.png", 154, 297-2, 24, "New game", 255, 255, 255);
		button[1].create(313, 282, 175, 43, "images/Nbutton1.png", 351, 295, 24, "Records", 255, 255, 255);
		button[2].create(218, 340, 175, 43, "images/Nbutton2.png", 277, 355-2, 24, "Menu", 255, 255, 255);
	}

	void destroy(){
		for (int i = 0; i < 3; i++)
			button[i].destroy();
	}

	Button getButton(int i){
		return button[i];
	}

	void setLevel(int level){
		this->level = level;
	}

	int getLevel(){
		return this->level;
	}

	void setOn(bool on){
		this->on = on;
	}

	bool getOn(){
		return this->on;
	}
};
#endif
