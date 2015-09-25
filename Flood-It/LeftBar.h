#ifndef _LEFTBAR_H_
#define _LEFTBAR_H_
class LeftBar : public Ground
{
private:
	int x, y, w, h, lvl;
public:
	void create(int x, int y, int w, int h,int level){
		setX(x);
		setY(y);
		setW(w);
		setH(h);
		change(level);
	}

	void destroy(){
	}
	void change(int lvl){
		setImg("images/LeftBar.png", x, y, w, h);
		if (lvl == 1){

			setImg("images/LevelLine1.png", x + w - 3, y, 3, 150);
			WriteText(30 - 8, 35, "1", 96, 255, 255, 255);
			WriteText(24, 102, "Level", 18, 255, 255, 255);

			WriteText(30 - 8, 186, "2", 96, 136, 136, 136);
			WriteText(24, 254, "Level", 18, 136, 136, 136);

			WriteText(30 - 8, 336, "3", 96, 136, 136, 136);
			WriteText(24, 404, "Level", 18, 136, 136, 136);
		}
		else
			if (lvl == 2){
				setImg("images/LevelLine2.png", x + w - 3, y + h / 3, 3, 150);
				WriteText(30 - 8, 35, "1", 96, 136, 136, 136);
				WriteText(24, 102, "Level", 18, 136, 136, 136);

				WriteText(30 - 8, 186, "2", 96, 255, 255, 255);
				WriteText(24, 254, "Level", 18, 255, 255, 255);

				WriteText(30 - 8, 336, "3", 96, 136, 136, 136);
				WriteText(24, 404, "Level", 18, 136, 136, 136);
			}
			else
				if (lvl == 3){
					setImg("images/LevelLine3.png", x + w - 3, y + (h / 3) * 2, 3, 150);
					WriteText(30 - 8, 35, "1", 96, 136, 136, 136);
					WriteText(24, 102, "Level", 18, 136, 136, 136);

					WriteText(30 - 8, 186, "2", 96, 136, 136, 136);
					WriteText(24, 254, "Level", 18, 136, 136, 136);

					WriteText(30 - 8, 336, "3", 96, 255, 255, 255);
					WriteText(24, 404, "Level", 18, 255, 255, 255);
				}

	}

	int check(int x, int y)
	{
		if (x >= this->x && x <= this->x + this->w)
		{
			if (y >= this->y && y <= this->y + this->h / 3)
			{
				return 1;
			}
			else
				if (y >= this->y + this->h / 3 && y <= this->y + (this->h / 3) * 2)
				{
					return 2;
				}
				else
					if (y >= this->y + (this->h / 3) * 2 / 3 && y <= this->y + this->h)
					{
						return 3;
					}
		}
		return 8;
	}

	void setX(int x){
		this->x = x;
	}
	int getX(){
		return x;
	}

	void setY(int y){
		this->y = y;
	}
	int getY(){
		return y;
	}

	void setW(int w){
		this->w = w;
	}
	int getW(){
		return w;
	}

	void setH(int h){
		this->h = h;
	}
	int getBH(){
		return h;
	}

	void setLVL(int lvl){
		this->lvl = lvl;
	}
	int getLVL(){
		return lvl;
	}
};
#endif

