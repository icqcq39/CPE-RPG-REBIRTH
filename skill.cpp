#include "skill.h"

//skill::skill(int i){
//	*this = load::getSkillData(i);
//}
//skill::skill(){
//	*this = load::getSkillData(0);
//}

int skill::getID(){
	return this->skillID;
}
string skill::getName(){
	return this->skillName;
}
int skill::getModPlayer(int index){
	return this->modPlayer[index];
}
int skill::getModWeapon(int index){
	return this->modWeapon[index];
}
int skill::getModArmor(int index){
	return this->modArmor[index];
}
double skill::getModPlayerAttack(int index){
	return this->modPlayerAttack[index];
}
int skill::getModMonster(int index){
	return this->modMonster[index];
}
double skill::getModMonsterAttack(int index){
	return this->modMonsterAttack[index];
}
int skill::getTurn(){
	return this->turn;
}
int skill::getCooldown(){
	return this->cooldown;
}
int skill::getDamage(){
	return this->damage;
}

void skill::setID(int id){
	this->skillID = id;
}
void skill::setName(string n){
	this->skillName = n;
}
string skill::getType(){
	return this->typeName;
}
void skill::setTurn(int t){
	this->turn = t;
}
void skill::setCooldown(int c){
	this->cooldown = c;
}
void skill::setModPlayer(string pack){//int,int,int,int,int
	pack = pack.substr(1,pack.find_first_of(']')-1);//  [x,x,x,x,x,] -> x,x,x,x,x, unpack
	for(int i=0; i<5;i++){
		this->modPlayer[i] = atoi(pack.substr(0,pack.find_first_of(',')).c_str());
		pack = pack.substr(pack.find_first_of(',')+1,pack.find_first_of('\0'));
	}
}
void skill::setModWeapon(string pack){//int,int,int
	pack = pack.substr(1,pack.find_first_of(']')-1);//  [x,x,x,x,x,] -> x,x,x,x,x, unpack
	for(int i=0; i<3;i++){
		this->modWeapon[i] = atoi(pack.substr(0,pack.find_first_of(',')).c_str());
		pack = pack.substr(pack.find_first_of(',')+1,pack.find_first_of('\0'));
	}
}
void skill::setModArmor(string pack){//int,int,int
	pack = pack.substr(1,pack.find_first_of(']')-1);//  [x,x,x,x,x,] -> x,x,x,x,x, unpack
	for(int i=0; i<3;i++){
		this->modArmor[i] = atoi(pack.substr(0,pack.find_first_of(',')).c_str());
		pack = pack.substr(pack.find_first_of(',')+1,pack.find_first_of('\0'));
	}
}
void skill::setModPlayerAttack(string pack){//double,double,double,double,double
	pack = pack.substr(1,pack.find_first_of(']')-1);//  [x,x,x,x,x,] -> x,x,x,x,x, unpack
	for(int i=0; i<5;i++){
		this->modPlayerAttack[i] = atof(pack.substr(0,pack.find_first_of(',')).c_str());
		pack = pack.substr(pack.find_first_of(',')+1,pack.find_first_of('\0'));
	}
}
void skill::setModMonster(string pack){//int,int,int,int,int
	pack = pack.substr(1,pack.find_first_of(']')-1);//  [x,x,x,x,x,] -> x,x,x,x,x, unpack
	for(int i=0; i<5;i++){
		this->modMonster[i] = atoi(pack.substr(0,pack.find_first_of(',')).c_str());
		pack = pack.substr(pack.find_first_of(',')+1,pack.find_first_of('\0'));
	}
}
void skill::setModMonsterAttack(string pack){//double,double,double,double,double
	pack = pack.substr(1,pack.find_first_of(']')-1);//  [x,x,x,x,x,] -> x,x,x,x,x, unpack
	for(int i=0; i<5;i++){
		this->modMonsterAttack[i] = atoi(pack.substr(0,pack.find_first_of(',')).c_str());
		pack = pack.substr(pack.find_first_of(',')+1,pack.find_first_of('\0'));
	}
}
void skill::setAll(int id,string name,int dmg,string mplayer,string mweapon,string marmor,string pattack,string mmonster,string mmattack,int t,int cd){
	this->setID(id);
	this->setName(name);
	this->setModPlayer(mplayer);
	this->setModWeapon(mweapon);
	this->setModArmor(marmor);
	this->setModPlayerAttack(pattack);
	this->setModMonster(mmonster);
	this->setModMonsterAttack(mmattack);
	this->setTurn(t);
	this->setCooldown(cd);
}
