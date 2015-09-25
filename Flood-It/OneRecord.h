#ifndef _ONERECORD_H_
#define _ONERECORD_H_
class OneRecord
{
private:
	std::string name;
	int step;
public:
	OneRecord(){
		name = "";
		step = 0;
	}

	OneRecord(std::string name, int step){
		setName(name);
		setStep(step);
	}

	void setStep(int step){
		this->step = step;
	}
	int getStep(){
		return step;
	}

	std::string getName(){
		return name;
	}
	void setName(std::string name){
		this->name = name;
	}
};
#endif