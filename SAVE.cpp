#include "SAVE.h"

int SAVE::getID(){
	return this->ID;
}
string SAVE::getName(){
	return this->name;
}
int SAVE::getPlayer(int i){
	return this->player[i];
}
int SAVE::getStory(int i){
	return this->story[i];
}
int SAVE::getAcode(){
	return this->acode;
}
int SAVE::getGold(){
	return this->gold;
}
vector<Item>* SAVE::getItemList(){
	return &this->itemList;
}
vector<skill>* SAVE::getSkillList(){
	return &this->skillList;
}
int SAVE::getPassiveId(){
	return this->passiveId;
}
int SAVE::getWeapon(){
	return this->weapon;
}
int SAVE::getArmor(){
	return this->armor;
}

void SAVE::setID(int id){
	this->ID = id;
}
void SAVE::setName(string name){
	this->name = name;
}
void SAVE::setStory(string pack){
	pack = pack.substr(1,pack.find_first_of(']')-1);
	for(int i=0; i<3;i++){
		this->story[i] = atoi(pack.substr(0,pack.find_first_of(',')).c_str());
		pack = pack.substr(pack.find_first_of(',')+1,pack.find_first_of('\0'));
	}
}
void SAVE::setPlayer(string pack){
	pack = pack.substr(1,pack.find_first_of(']')-1);
	for(int i=0; i<4;i++){
		this->player[i] = atoi(pack.substr(0,pack.find_first_of(',')).c_str());
		pack = pack.substr(pack.find_first_of(',')+1,pack.find_first_of('\0'));
	}
}
void SAVE::setItemList(string pack){
	pack = pack.substr(1,pack.find_first_of(']'));//  [x,x,x,] -> x,x,x,]
	while(pack != "]"){
		this->addItemList(atoi(pack.substr(0,pack.find_first_of(',')).c_str() ));
		pack = pack.substr(pack.find_first_of(',')+1,pack.find_first_of('\0'));
	}
}
void SAVE::setSkillList(string pack){
	pack = pack.substr(1,pack.find_first_of(']'));//  [x,x,x,] -> x,x,x,]
	while(pack != "]"){
		this->addSkillList(atoi(pack.substr(0,pack.find_first_of(',')).c_str() ));
		pack = pack.substr(pack.find_first_of(',')+1,pack.find_first_of('\0'));
	}
}
void SAVE::setAcode(int a){
	this->acode = a;
}
void SAVE::setGold(int g){
	this->gold = g;

}
void SAVE::addItemList(int i){
	this->getItemList()->push_back(load::getItemData(i));
}
void SAVE::addSkillList(int i){
	this->getSkillList()->push_back(load::getSkillData(i));
}
void SAVE::setPassive(int p){
	this->passiveId = p;
}
void SAVE::setWeapon(int w){
	this->weapon = w;
}
void SAVE::setArmor(int a){
	this->armor = a;
}
void SAVE::setAll(int id,string name,string story,string player,int ac,int g,string itP,string skP,int p,int w,int a){
	this->setID(id);
	this->setName(name);
	this->setAcode(ac);
	this->setGold(g);
	this->setPassive(p);
	this->setArmor(a);
	this->setWeapon(w);
	this->setStory(story);
	this->setPlayer(player);
	this->setItemList(itP);
	this->setSkillList(skP);
	
}
