#include "LeftBar.h"
#include "Button.h"
#include "ReadRecords.h"
#ifndef _RECORDS_H_
#define _RECORDS_H_
class Records : public Ground
{
private:
	bool on;
	Button button;
	LeftBar leftbar;
	ReadRecord readrecord;
	std::list<OneRecord> list;
public:
	void create(int level){
		setON(true);

		CreateBackground("images/Background.png");
		leftbar.create(0, 0, 100, 450,level);		
		button.create(258, 395, 175, 43, "images/Nbutton2.png", 317, 409, 24, "Menu", 255, 255, 255);
		drawRecords(level);	
	}

	void destroy(){
		button.destroy();
		leftbar.destroy();
		setON(false);
	}

	void drawRecords(int level){
		list.clear();
		list = readrecord.getlist(level);
		readrecord.destroy();
		setImg("images/RecordBoard.jpg", 130, 30, 430, 352);
		WriteText(153, 48, "#", 18, 136, 136, 136);
		WriteText(204, 48, "Name", 18, 136, 136, 136);
		WriteText(484, 48, "Steps", 18, 136, 136, 136);
		int i = 0;		
		for (std::list<OneRecord>::iterator it = list.begin(); it != list.end(); it++){
			setImg("images/Line.png", 150, 69 + (i * 30), 390, 1);
			char tmpch[10];
			for (int j = 0; j < 10; j++) tmpch[j] = 0;
			sprintf_s(tmpch, "%d.", i+1);			
			WriteText(153, 69 + (i * 30) + 10, tmpch, 18, 255, 255, 255);
			for (int i = 0; i < 10; i++) tmpch[i] = 0;
			for (int j = 0; j <it->getName().size(); j++){
				if (it->getName()[j] == '_')
					tmpch[j] = ' ';
				else
					tmpch[j] = it->getName()[j];
			}
			WriteText(204, 69 + (i * 30) + 10, tmpch, 18, 255, 255, 255);
			sprintf_s(tmpch, "%d", it->getStep());
			WriteText(484, 69 + (i * 30) + 10, tmpch, 18, 255, 255, 255);
			i++;
		}
		getleftbar().change(level);
	}

	Button getButton(){
		return button;
	}

	LeftBar getleftbar(){
		return leftbar;
	}

	void setON(bool on){
		this->on = on;
	}
	bool getON(){
		return on;
	}

};
#endif

