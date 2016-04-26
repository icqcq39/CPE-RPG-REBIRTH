#include "head.h"

#ifndef SKILL_H
#define SKILL_H
class skill{
	public:
//		skill();
//		skill(int);
		
		int getID();
		string getName();
		string getType();
		int getModPlayer(int);
		int getModWeapon(int);
		int getModArmor(int);
		double getModPlayerAttack(int);
		int getModMonster(int);
		double getModMonsterAttack(int);
		int getDamage();
		int getTurn();
		int getCooldown();
		
		void setID(int);
		void setName(string);
		void setTurn(int);
		void setCooldown(int);
		void setModPlayer(string);//int,int,int,int,int
		void setModWeapon(string);//int,int,int
		void setModArmor(string);//int,int,int
		void setModPlayerAttack(string);//double,double,double,double,double
		void setModMonster(string);//int,int,int,int,int
		void setModMonsterAttack(string);//double,double,double,double,double
		void setAll(int,string,int,string,string,string,string,string,string,int,int);
		
	private:
		int skillID;
		string skillName;
		string typeName = "SKILL";
		int damage;
		int modPlayer[5];// ATK , DEF , MAXHP , HP , GOLD
		int modWeapon[3];// ATK , DEF , MAXHP
		int modArmor[3];// ATK , DEF , MAXHP
		double modPlayerAttack[5];// dmgFactor , hitNumber , hitChance , criChance , criFactor
		int modMonster[5];// ATK , DEF , MAXHP , HP , GOLD
		double modMonsterAttack[5];// dmgFactor , hitNumber , hitChance , criChance , criFactor
		int turn;
		int cooldown;
		
};

#endif
