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
void Shop::setSellList(string pack){
	pack = pack.substr(1,pack.find_first_of(']'));//  [x,x,x,] -> x,x,x,]
	while(pack != "]"){
		this->addItem(atoi(pack.substr(0,pack.find_first_of(',')).c_str() ));
		pack = pack.substr(pack.find_first_of(',')+1,pack.find_first_of('\0'));
	}
}
void Shop::setAll(int id,int sid,string pack){
	this->setID(id);
	this->setShopID(sid);
	this->setSellList(pack);
}
void Shop::printSellList(){
	for(int i=0;i<this->getSellList()->size();i++){
		cout << "\t["<<i<<"] "<<getSellList()->at(i).getName()<<endl;
	}
}
