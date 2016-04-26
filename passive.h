#include "head.h"

#ifndef PASSIVE_H
#define PASSIVE_H
class passive{
	public:
		int getID();
		string getName();
		string getType();
		double getDmgFactor();
		double getMoneyFactor();
		double getDropFactor();
		double getStatFactor();
		double getCriFactor();
		int getCriChanceAdd();
		int getStatAdd();
		
		void setID(int);
		void setName(string);
		void setDmgFactor(double);
		void setMoneyFactor(double);
		void setDropFactor(double);
		void setStatFactor(double);
		void setCriFactor(double);
		void setCriChanceAdd(int);
		void setStatAdd(int);
		void setAll(int,string,double,double,double,double,double,int,int);
		
	private:
		double dmgFactor;
		double moneyFactor;
		double dropFactor;
		double statFactor;
		double criFactor;
		int criChanceAdd;
		int statAdd;
		int passiveID;
		string passiveName;
		string typeName = "PASSIVE";
};

#endif
