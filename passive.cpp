#include "passive.h"

int passive::getID(){
	return this->passiveID;
}
string passive::getName(){
	return this->passiveName;
}
string passive::getType(){
	return this->typeName;
}
double passive::getDmgFactor(){
	return this->dmgFactor;
}
double passive::getMoneyFactor(){
	return this->moneyFactor;
}
double passive::getDropFactor(){
	return this->dropFactor;
}
double passive::getStatFactor(){
	return this->statFactor;
}
double passive::getCriFactor(){
	return this->criFactor;
}
int passive::getCriChanceAdd(){
	return this->criChanceAdd;
}
int passive::getStatAdd(){
	return this->statAdd;
}

void passive::setID(int id){
	this->passiveID = id;
}
void passive::setName(string n){
	this->passiveName = n;
}
void passive::setDmgFactor(double dmgF){
	this->dmgFactor = dmgF;
}
void passive::setMoneyFactor(double mnF){
	this->moneyFactor = mnF;
}
void passive::setDropFactor(double dF){
	this->dropFactor = dF;
}
void passive::setStatFactor(double sF){
	this->statFactor = sF;
}
void passive::setCriFactor(double cF){
	this->criFactor = cF;
}
void passive::setCriChanceAdd(int cA){
	this->criChanceAdd = cA;
}
void passive::setStatAdd(int sA){
	this->statAdd = sA;
}
void passive::setAll(int id,string name,double dmgF,double mnF,double dF,double stF,double cF,int cA,int stA){
	this->setID(id);
	this->setName(name);
	this->setDmgFactor(dmgF);
	this->setMoneyFactor(mnF);
	this->setDropFactor(dF);
	this->setStatFactor(stF);
	this->setCriFactor(cF);
	this->setCriChanceAdd(cA);
	this->setStatAdd(stA);

}
