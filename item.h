#include "head.h"

#ifndef ITEM_H
#define ITEM_H

class Item{
	public:
		int getID();
		string getName();
		int getPB();
		int getPS();
		string getDetail();
		string getType();
		int getiAtk();
		int getiDef();
		int getiHp();
		string getItemType();
		int getiMaxHp();
		int getAttackIndex();
		
		void setID(int);
		void setName(string);
		void setPB(int);
		void setPS(int);
		void setDetail(string);
		void setiAtk(int);
		void setiDef(int);
		void setiHp(int);
		void setItemType(string);
		void setiMaxHp(int);
		void setAll(int,string,int,int,string,int,int,int,int,int,string);
		void setAttackIndex(int);
		
		Item(int,string,int,int,string,int,int,int,int,int,string);
		Item(int);
		Item();
		
		void printItem();
	private:
		string typeName = "ITEM";
		int itemID;
		string itemName;
		int itemPriceB;
		int itemPriceS;
		string itemDetail;
		int iAtk;
		int iDef;
		int iMaxHp;
		int iHp;
		int attackIndex;
		string itemType = " ";//WEAPON,ARMOR,CONSUMABLE,ETC
		
};

//class Weapon: public Item{
//	public:
//		int getiAtk();
//		void setiAtk(int);
//		int getiDef();
//		void setiDef(int);
//		int getiHp();
//		void setiHp(int);
//	protected:
//		
//};
//
//class Armor: public Item{
//	public:
//		int getiAtk();
//		void setiAtk(int);
//		int getiDef();
//		void setiDef(int);
//		int getiHp();
//		void setiHp(int);
//	protected:
//		int iAtk;
//		int iDef;
//		int iHp;
//};
//
//class Consumable: public Item{
//	public:
//		int getiAtk();
//		void setiAtk(int);
//		int getiDef();
//		void setiDef(int);
//		int getiHp();
//		void setiHp(int);
//	protected:
//		int iAtk;
//		int iDef;
//		int iHp;
//};
#endif
