#include "monster.h"



string monster::getType(){
	return this->typeName;
}
status* monster::getStat(){
	return &this->stat;
}
string monster::getName(){
	return this->name;
}
string monster::getClass(){
	return this->Class;
}
int monster::getMonID(){
	return this->monID;
}
vector<monsterMove>* monster::getAttackMove(){
	return &this->attackMove;
}
skill monster::getMonSkill(){
	return this->monSkill;
}
int monster::getGold(){
	return this->gold;
}
vector<string>* monster::getDropList(){
	return &this->dropList;
}

void monster::setName(string n){
	this->name = n;
}
void monster::setClass(string c){
	this->Class = c;
}
void monster::setMonID(int id){
	this->monID = id;
}
void monster::addAttack(int index){
	this->getAttackMove()->push_back(load::getMonAttackData(index));
}
void monster::setSkill(int index){
	this->monSkill = load::getSkillData(index);
}
void monster::setGold(int g){
	this->gold = g;
}
void monster::addDrop(string item){
	this->dropList.push_back(item);
}
void monster::setAll(int id,string name,int atk,int def,int hp,string cls,int sk,string move,string drop){

	this->setMonID(id);
	this->setName(name);
	this->getStat()->setAll(atk,def,hp);
	this->setClass(cls);
	this->setSkill(sk);

	move = move.substr(1,move.find_first_of(']'));//  [x,x,x,] -> x,x,x,]
	
	while(move != "]"){
		this->addAttack(atoi(move.substr(0,move.find_first_of(',')).c_str() ));
		move = move.substr(move.find_first_of(',')+1,move.find_first_of('\0'));
	}
	
	drop = drop.substr(1,drop.find_first_of(']'));//  [x,x,x,] -> x,x,x,]
	while(drop != "]"){
		this->addDrop(drop.substr(0,move.find_first_of(',')));
		drop = drop.substr(drop.find_first_of(',')+1,drop.find_first_of('\0'));
	}
}
