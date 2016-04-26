#include "head.h"

#ifndef SHOP_H
#define SHOP_H

class Shop{
	public:
		int getID();
		int getShopID();
		vector<Item>* getSellList();
		
		void setID(int);
		void setShopID(int);
		void addItem(int);
	private:
		int ID;
		int shopID;
		vector<Item> sellList;
	
};
#endif
