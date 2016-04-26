#include "item.h"

//Class Item

int Item::getID(){
	return this->itemID;
}

string Item::getName(){
	return this->itemName;
}

int Item::getPB(){
	return this->itemPriceB;
}

int Item::getPS(){
	return this->itemPriceS;
}

string Item::getDetail(){
	return this->itemDetail;
}

void Item::setID(int a){
	this->itemID = a;
}

void Item::setName(string a){
	this->itemName = a;
}

void Item::setPB(int a){
	this->itemPriceB = a;
}

void Item::setPS(int a){
	this->itemPriceS = a;
}

void Item::setDetail(string a){
	this->itemDetail = a;
}


int Item::getiAtk(){
	return this->iAtk;
}

int Item::getiDef(){
	return this->iDef;
}
int Item::getiHp(){
	return this->iHp;
}

void Item::setiAtk(int a){
	this->iAtk = a;
}

void Item::setiDef(int a){
	this->iDef = a;
}

void Item::setiHp(int a){
	this->iHp = a;
}

string Item::getType(){
		return this->typeName;
}

string Item::getItemType(){
	return this->itemType;
}

void Item::setItemType(string typ){
	this->itemType = typ;
}

int Item::getiMaxHp(){
	return this->iMaxHp;
}

void Item::setiMaxHp(int x){
	this->iMaxHp = x;
}

void Item::setAll(int id,string name,int SP,int BP,string type,int atk,int def,int hp,int max,int attIndex,string desc){
	this->setID(id);
	this->setName(name);
	this->setPS(SP);
	this->setPB(BP);
	this->setItemType(type);
	this->setiAtk(atk);
	this->setiDef(def);
	this->setiHp(hp);
	this->setiMaxHp(max);
	this->setAttackIndex(attIndex);
	this->setDetail(desc);
}

Item::Item(int id,string name,int SP,int BP,string type,int atk,int def,int hp,int max,int attIndex,string desc){
	this->setAll(id,name,SP,BP,type,atk,def,hp,max,attIndex,desc);
}

Item::Item(){
//	this->setAll(0,"DUMMY",0,0,"WEAPON",0,0,0,"NULL","NULL");
}

Item::Item(int id){
	*this = load::getItemData(id);;	
}

void Item::printItem(){
	cout << getID() << ", " << getName() << ", " << getPS() << ", " << getPB() << ", " << getItemType() << ", " << getiAtk() << ", " << 
			getiDef() << ", " << getiHp() << ", " << getiMaxHp() << ", " << getDetail() <<"\n";
}

int Item::getAttackIndex(){
	return this->attackIndex;
}

void Item::setAttackIndex(int index){
	this->attackIndex = index;
}

