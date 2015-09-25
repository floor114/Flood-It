#ifndef _CHOOSE_H_
#define _CHOOSE_H_
class ChooseLevel : public Ground
{
private:
	bool on;
	Button button[4];
public:
	void create(){
		setON(true);
		CreateBackground("images/Background.png");
		setImg("images/LevelBoard1.png", 83, 77, 128, 256);
		setImg("images/LevelBoard2.png", 231, 77, 128, 256);
		setImg("images/LevelBoard3.png", 379, 77, 128, 256);
		WriteText(100 - 2, 232, "14x14", 33, 255, 255, 255);
		WriteText(248 - 2, 232, "21x21", 33, 255, 255, 255);
		WriteText(396 - 2, 232, "28x28", 33, 255, 255, 255);
		WriteText(110, 112, "1", 128, 255, 255, 255);
		WriteText(268 - 10, 112, "2", 128, 255, 255, 255);
		WriteText(415 - 10, 112, "3", 128, 255, 255, 255);
		button[0].create(208, 378, 175, 43, "images/Nbutton2.png", 267, 390, 24, "Back", 255, 255, 255);
		button[1].create(130, 277, 35, 40, "images/PlayButton.png", 0, 0, 0, "", 0, 0, 0);
		button[2].create(278, 277, 35, 40, "images/PlayButton.png", 0, 0, 0, "", 0, 0, 0);
		button[3].create(426, 277, 35, 40, "images/PlayButton.png", 0, 0, 0, "", 0, 0, 0);
	}

	void destroy(){
		for (int i = 0; i < 4; i++){
			button[i].destroy();
		}
		setON(false);
	}

	Button getButton(int i){
		return button[i];
	}

	void setON(bool on){
		this->on = on;
	}
	bool getON(){
		return on;
	}

};
#endif

