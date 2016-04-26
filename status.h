#include "head.h"

#ifndef STATUS_H
#define STATUS_H

class status{
	public:
		status(int,int,int);
		status(int);
		status();
		
		int getAtk();
		int	getDef();
		int getHp();
		int getMaxhp();
		string getType();
		
		void setAtk(int);
		void setDef(int);
		void setHp(int);
		void setMaxhp(int);
		void setAll(int, int, int);
		void addAll(int,int,int);
		void takeDamage(int);
		
		void addAtk(int);
		void addDef(int);
		void addHp(int);
		void addMaxhp(int);
		
		void randomize();

	private:
		int atk;
		int def;
		int hp;
		int maxHp;
		string typeName = "STATUS";
	
};

#endif

