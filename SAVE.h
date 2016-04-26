#include "head.h"

#ifndef SAVE_H
#define SAVE_H

class SAVE{
	public:
		int getID();
		string getName();
		int getPlayer(int);
		int getStory(int);
		int getAcode();
		int getGold();
		vector<Item>* getItemList();
		vector<skill>* getSkillList();
		int getPassiveId();
		int getWeapon();
		int getArmor();
		
		void setID(int);
		void setName(string);
		void setStory(string);
		void setPlayer(string);
		void setAcode(int);
		void setGold(int);
		void addItemList(int);
		void addSkillList(int);
		void setPassive(int);
		void setWeapon(int);
		void setArmor(int);
		void setItemList(string);
		void setSkillList(string);
		void setAll(int,string,string,string,int,int,string,string,int,int,int);
	
	private:
		int ID;
		string name;
		int story[3];
		int player[4];
		int acode;
		int gold;
		vector<Item> itemList;
		vector<skill> skillList;
		int passiveId;
		int weapon;
		int armor;
		
	
};
#endif
