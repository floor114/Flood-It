#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_
class KeyButton{
public:
	Button button;
	char keyUp[6],keyDown[6];
	void create(int bx, int by, int bw, int bh, char fileButtonImg[40], int tx, int ty, int tsize, char buttonText[10], int r, int g, int b, char keyUp[6], char keyDown[6]){
		button.create(bx, by, bw, bh, fileButtonImg, tx, ty, tsize, buttonText, r, g, b);
		strcpy_s(this->keyUp, keyUp);
		strcpy_s(this->keyDown, keyDown);
	}

	void destroy(){ 
		button.destroy(); 
	}
};

class Keyboard : public Ground
{
private:
	bool on,inputing;
	KeyButton button[35];
	std::string str;
	bool keyshift = false;
public:
	void create(){
		setON(true);
		CreateBackground("images/Background.png");
		setImg("images/EditText.png", 198, 140, 193, 49);
		ClearWindow(0, 258, 590, 192, 0, 0, 0);
		WriteText(180, 103, "Enter name:", 36, 255, 255, 255);
		button[0].create(11 + (0 * 48), 271, 43, 38, "images/KeySpace.png", 25+(0 * 48), 280, 24, "q", 255, 255, 255,"Q","q");
		button[1].create(11 + (1 * 48), 271, 43, 38, "images/KeySpace.png", 25+(1 * 48), 280, 24, "w", 255, 255, 255,"W","w");
		button[2].create(11 + (2 * 48), 271, 43, 38, "images/KeySpace.png", 25+(2 * 48), 280, 24, "e", 255, 255, 255,"E","e");
		button[3].create(11 + (3 * 48), 271, 43, 38, "images/KeySpace.png", 25+(3 * 48), 280, 24, "r", 255, 255, 255,"R","r");
		button[4].create(11 + (4 * 48), 271, 43, 38, "images/KeySpace.png", 25+(4 * 48), 280, 24, "t", 255, 255, 255,"T","t");
		button[5].create(11 + (5 * 48), 271, 43, 38, "images/KeySpace.png", 25+(5 * 48), 280, 24, "y", 255, 255, 255,"Y","y");
		button[6].create(11 + (6 * 48), 271, 43, 38, "images/KeySpace.png", 25+(6 * 48), 280, 24, "u", 255, 255, 255,"U","u");
		button[7].create(11 + (7 * 48), 271, 43, 38, "images/KeySpace.png", 25+(7 * 48), 280, 24, "i", 255, 255, 255,"I","i");
		button[8].create(11 + (8 * 48), 271, 43, 38, "images/KeySpace.png", 25+(8 * 48), 280, 24, "o", 255, 255, 255,"O","o");
		button[9].create(11 + (9 * 48), 271, 43, 38, "images/KeySpace.png", 25+(9 * 48), 280, 24, "p", 255, 255, 255,"P","p");
		
		button[10].create(491, 271, 88, 38, "images/KeySpace.png", 521, 280, 24, "<=", 255, 255, 255, "<=","");

		button[0 + 11].create(21 + (0 * 48), 314, 43, 38, "images/KeySpace.png", 35 + (0 * 48), 323, 24, "a", 255, 255, 255, "A", "a");
		button[1 + 11].create(21 + (1 * 48), 314, 43, 38, "images/KeySpace.png", 35 + (1 * 48), 323, 24, "s", 255, 255, 255, "S", "s");
		button[2 + 11].create(21 + (2 * 48), 314, 43, 38, "images/KeySpace.png", 35 + (2 * 48), 323, 24, "d", 255, 255, 255, "D", "d");
		button[3 + 11].create(21 + (3 * 48), 314, 43, 38, "images/KeySpace.png", 35 + (3 * 48), 323, 24, "f", 255, 255, 255, "F", "f");
		button[4 + 11].create(21 + (4 * 48), 314, 43, 38, "images/KeySpace.png", 35 + (4 * 48), 323, 24, "g", 255, 255, 255, "G", "g");
		button[5 + 11].create(21 + (5 * 48), 314, 43, 38, "images/KeySpace.png", 35 + (5 * 48), 323, 24, "h", 255, 255, 255, "H", "h");
		button[6 + 11].create(21 + (6 * 48), 314, 43, 38, "images/KeySpace.png", 35 + (6 * 48), 323, 24, "j", 255, 255, 255, "J", "j");
		button[7 + 11].create(21 + (7 * 48), 314, 43, 38, "images/KeySpace.png", 35 + (7 * 48), 323, 24, "k", 255, 255, 255, "K", "k");
		button[8 + 11].create(21 + (8 * 48), 314, 43, 38, "images/KeySpace.png", 35 + (8 * 48), 323, 24, "l", 255, 255, 255, "L", "l");
		button[9 + 11].create(21 + (9 * 48), 314, 43, 38, "images/KeySpace.png", 35 + (9 * 48), 323, 24, "'", 255, 255, 255, "'", "'");

		button[21].create(501, 314, 78, 38, "images/KeySpace.png", 514, 327, 18, "Enter", 255, 255, 255, "Enter","");
		
		button[0 + 23].create(104 + (0 * 48), 357, 43, 38, "images/KeySpace.png", 118 + (0 * 48), 366, 24, "z", 255, 255, 255, "Z", "z");
		button[1 + 23].create(104 + (1 * 48), 357, 43, 38, "images/KeySpace.png", 118 + (1 * 48), 366, 24, "x", 255, 255, 255, "X", "x");
		button[2 + 23].create(104 + (2 * 48), 357, 43, 38, "images/KeySpace.png", 118 + (2 * 48), 366, 24, "c", 255, 255, 255, "C", "c");
		button[3 + 23].create(104 + (3 * 48), 357, 43, 38, "images/KeySpace.png", 118 + (3 * 48), 366, 24, "v", 255, 255, 255, "V", "v");
		button[4 + 23].create(104 + (4 * 48), 357, 43, 38, "images/KeySpace.png", 118 + (4 * 48), 366, 24, "b", 255, 255, 255, "B", "b");
		button[5 + 23].create(104 + (5 * 48), 357, 43, 38, "images/KeySpace.png", 118 + (5 * 48), 366, 24, "n", 255, 255, 255, "N", "n");
		button[6 + 23].create(104 + (6 * 48), 357, 43, 38, "images/KeySpace.png", 118 + (6 * 48), 366, 24, "m", 255, 255, 255, "M", "m");
		button[7 + 23].create(104 + (7 * 48), 357, 43, 38, "images/KeySpace.png", 118 + (7 * 48), 366, 24, ",", 255, 255, 255, ",", ",");
		button[8 + 23].create(104 + (8 * 48), 357, 43, 38, "images/KeySpace.png", 118 + (8 * 48), 366, 24, ".", 255, 255, 255, ".", ".");
		button[9 + 23].create(104 + (9 * 48), 357, 43, 38, "images/KeySpace.png", 118 + (9 * 48), 366, 24, "?", 255, 255, 255, "?", "?");		
		
		button[33].create(11, 357, 88, 38, "images/KeySpace.png", 51, 373, 24, "^", 255, 255, 255, "^","");
		button[34].create(130, 400, 331, 38, "images/KeySpace.png", 0, 0, 0, " ", 0, 0, 0, "_","_");
	}

	void destroy(){
		setON(false);
		for (int i = 0; i < 35; i++)
			button[i].destroy();
	}

	void check(int x, int y){		
		inputing = true;
		std::string tmp = str;
		int k = -1;
		for (int i = 0; i < 35; i++){
			if (button[i].button.check(x, y)) {
				k = i;
				break;
			}
		}
		if (k != -1){
			if (k == 10){
				if (str.length()>0) str.erase(str.length() - 1);
			}
			if (k == 33){
				if (!keyshift){
					keyshift = !keyshift;
					button[33].destroy();
					button[33].create(11, 357, 88, 38, "images/KeySpace.png", 51, 373, 24, "^", 41, 207, 115, "^", "");
				}
				else{
					keyshift = !keyshift;
					button[33].destroy();
					button[33].create(11, 357, 88, 38, "images/KeySpace.png", 51, 373, 24, "^", 255, 255, 255, "^", "");
				}
			}
			if (k == 21 && str.length() > 0){
				destroy();
				inputing = false;
			}
			if (str.length() <= 8){
				if (k != 10 && k != 33 && k != 21){
					if (keyshift){
						if (button[k].keyUp == "_")
							str += ' ';
						else
							str += button[k].keyUp;
					}
					else
						if (button[k].keyDown == "_")
							str += ' ';
						else
							str += button[k].keyDown;
				}
			}
			if (str != tmp){
				char tmpch[10] = { " " };

				for (int j = 0; j < str.size(); j++){
					if (str[j] == '_')
						tmpch[j] = ' ';
					else
						tmpch[j] = str[j];
				}

				ClearWindow(209, 150, 170, 30, 241, 196, 15);
				WriteText(211 - 3, 153 - 2, tmpch, 32, 255, 255, 255);
			}
		}
		
	}

	KeyButton getButton(int i){
		return button[i];
	}

	void clearStr(){
		str = "";
	}

	std::string getName(){
		return str;
	}

	bool getInputing(){
		return inputing;
	}

	void setON(bool on){
		this->on = on;
	}
	bool getON(){
		return on;
	}
};

#endif

