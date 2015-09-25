#ifndef _Button_H_
#define _Button_H_
class Button :
	public Ground
{
private:
	int bx, by, bw, bh, tx, ty, tsize, r, g, b;
	char fileName[40];
	char text[10];
public:
	void create(int bx, int by, int bw, int bh, char fileButtonImg[40], int tx, int ty, int tsize, char buttonText[10], int r, int g, int b){
		setBX(bx);
		setBY(by);
		setBW(bw);
		setBH(bh);
		this->r = r;
		this->g = g;
		this->b = b;
		setFileName(fileButtonImg);
		setImg(fileButtonImg, bx, by, bw, bh);
		setTX(tx);
		setTY(ty);
		setTSize(tsize);
		setText(buttonText, tx, ty, tsize, r, g, b);
	}

	void destroy(){
	}

	void pressed(){
		char tmp[40];
		strcpy_s(tmp, fileName);
		for (int i = 0; i < strlen(tmp); i++)
			if (tmp[i] == '/') tmp[i + 1] = 'D';
		setImg(tmp, bx, by, bw, bh);
		setText(text, tx, ty, tsize, r, g, b);
		SDL_Delay(100);
		setImg(fileName, bx, by, bw, bh);
		setText(text, tx, ty, tsize, r, g, b);
		SDL_Delay(100);
	}

	bool check(int x, int y)
	{
		if (x >= bx && x <= bx + bw)
		{
			if (y >= by && y <= by + bh)
			{
				return true;
			}
		}
		return false;
	}

	void setText(char txt[10], int tx, int ty, int tsize, int r, int g, int b){
		strcpy_s(text, txt);
		WriteText(tx, ty, text, tsize, r, g, b);
	}

	void setFileName(char filename[40]){
		strcpy_s(fileName, filename);
	}

	void setBX(int x){
		this->bx = x;
	}
	int getBX(){
		return bx;
	}

	void setBY(int y){
		this->by = y;
	}
	int getBY(){
		return by;
	}

	void setBW(int w){
		this->bw = w;
	}
	int getBW(){
		return bw;
	}

	void setBH(int h){
		this->bh = h;
	}
	int getBH(){
		return bh;
	}

	void setTX(int x){
		this->tx = x;
	}
	int getTX(){
		return tx;
	}

	void setTY(int y){
		this->ty = y;
	}
	int getTY(){
		return ty;
	}

	void setTSize(int size){
		this->tsize = size;
	}
	int getTSize(){
		return tsize;
	}
};
#endif
