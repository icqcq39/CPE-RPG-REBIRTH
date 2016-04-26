#include "shop.h"


int Shop::getID(){
	return this->ID;
}
int Shop::getShopID(){
	return this->shopID;
}
vector<Item>* Shop::getSellList(){
	return &this->sellList;
}

void Shop::setID(int id){
	this->ID = id;
}
void Shop::setShopID(int sID){
	this->shopID = sID;
}
void Shop::addItem(int index){
	this->sellList.push_back(load::getItemData(index));
}
