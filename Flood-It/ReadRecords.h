#include "OneRecord.h"
#ifndef _ReadRecords_H_
#define _ReadRecords_H_
class ReadRecord{
private:
	std::list <OneRecord> list;
	int level;
public:
	void destroy(){
		list.clear();
	}
	void readRecord(int level){
		char path[20];
		sprintf_s(path, "Flood-It%d.dat", level);
		std::ifstream fin(path, std::ios::binary);
		list.clear();
		if (fin.is_open()){
			int i = 0;
			while (!fin.eof()){
				int tmps; std::string tmpn;
				fin >> tmpn; fin >> tmps;
				OneRecord tmpl(tmpn, tmps);
				list.push_back(tmpl);
				if (i > 8) break;
				i++;				
			}
		}
		else{
			OneRecord tmpl("None", 0);
			list.push_back(tmpl);
		}
		fin.close();		
	}

	void saveRecords(int level,std::string name,int step){
		if (list.front().getStep() == 0) list.clear();
		std::cout << name << std::endl;
		OneRecord tmpl(name, step);
		list.push_back(tmpl);
		list.sort([](OneRecord lhs, OneRecord rhs) {return lhs.getStep() < rhs.getStep(); });
		char path[20];
		sprintf_s(path, "Flood-It%d.dat", level);
		std::ofstream os(path, std::ios::binary);
		int i = 0;
		for (std::list<OneRecord>::iterator it = list.begin(); it != list.end(); it++){
			if (it == list.begin())
				os << it->getName() << '\n';
			else
				os << '\n' << it->getName() << '\n';
			os << it->getStep();
			if (i > 8) break;
			i++;
		}
		os.close();
	}

	std::list<OneRecord> getlist(int level){
		readRecord(level);
		return list;
	}

	int getNumbOfRec(){
		int i = 0;
		for (std::list<OneRecord>::iterator it = list.begin(); it != list.end(); it++){
			i++;
		}
		return i;
	}

	int getRecord(){
		return list.front().getStep();
	}

	void setLevel(bool level){
		this->level = level;
	}

	bool getLevel(){
		return this->level;
	}
};
#endif