#include "player.h"

player::player(){
	this->setName("PLAYER");
	this->setGold(0);
	this->setACode(0);
	this->setWeapon(0);
	this->setArmor(0);
	this->setACode(1);
	this->setPassive(0);
	this->getStat()->randomize();
}

player::player(string n){
	this->setName(n);
	this->setGold(0);
	this->setACode(0);
	this->setWeapon(0);
	this->setArmor(0);
	this->setACode(1);
	this->setPassive(0);
	this->getStat()->randomize();
}

status* player::getStat(){
	return &this->stat;
}

string player::getName(){
	string s = this->name;
	return s;
}

int player::getGold(){
	return this->gold;
}

void player::setGold(int gold){
	this->gold = gold;
}

void player::setName(string tmp){
	this->name = tmp;
}

void player::addGold(int amount){
	this->setGold(getGold() + amount);
}

Place player::getACode(){
	return load::getPlaceData(this->aCode);
}

void player::setACode(int target){
	this->aCode = target;
}

void player::addItem(int itemID){
	this->getItemList()->push_back(load::getItemData(itemID));
}

vector<Item>* player::getItemList(){
	return &this->inventory;
}

void player::delItem(int index){
	this->getItemList()->erase(this->getItemList()->begin() + index);
}
void player::delItem(int id,int amount){
	for(int j=0;j<amount;j++){
		for(int i=0;i<getItemList()->size();i++){
			if(getItemList()->at(i).getID() == id){
				this->delItem(i);
				break;
			}
		}
	}
	
}
void player::setPassive(int p){
	this->myPassive = load::getPassiveData(p);
}

passive player::getPassive(){
	return this->myPassive;
}

bool player::setWeapon(int w){
	if(load::getItemData(w).getItemType() == "WEAPON"){
		this->myWeapon = load::getItemData(w);
		this->setAttack(load::getItemData(w).getAttackIndex());
		return true;
	}else{
		this->myWeapon = load::getItemData(1);
		this->setAttack(1);
		return false;
	}
}

bool player::setArmor(int a){
	if(load::getItemData(a).getItemType() == "ARMOR"){
		this->myArmor = load::getItemData(a);
		return true;
	}else{
		this->myArmor = load::getItemData(2);
		return false;
	}
}

Item player::getWeapon(){
	return this->myWeapon;
}

Item player::getArmor(){
	return this->myArmor;
}

string player::getType(){
	return this->typeName;
}

void player::addSkill(int sk){
	this->getSkillList()->push_back(load::getSkillData(sk));
}

vector<skill>* player::getSkillList(){
	return &this->mySkill;
}

attack player::getAttack(){
	return this->myAttack;
}

void player::setAttack(int att){
	this->myAttack = load::getAttackData(att);
}
bool player::showItemList(){
	bool flag=false;
	for(int i=0;i<this->getItemList()->size();i++){
		flag = true;
		cout << "\t["<<i<<"] "<<setw(15)<<getItemList()->at(i).getName()<<setw(15)<<"["<<getItemList()->at(i).getDetail()<<"]"<<endl;
	}
	return flag;
}
bool player::showItemList(string type){
	bool flag=false;
	for(int i=0;i<this->getItemList()->size();i++){
		if(this->getItemList()->at(i).getItemType() == type){
			flag = true;
			cout << "["<<i<<"] "<<getItemList()->at(i).getName()<<endl;
		}
	}
	return flag;
}
bool player::showSkillList(){
	bool flag=false;
	for(int i=0;i<this->getSkillList()->size();i++){
		flag = true;
		cout << "\t["<<i<<"] "<<setw(15)<<getSkillList()->at(i).getName()<<endl;
	}
	return flag;
}
void player::use(int index){
	//WEAPON,ARMOR,CONSUMABLE,ETC
	Item tmp = load::getItemData(getItemList()->at(index).getID());
	if(tmp.getItemType() == "WEAPON"){
		getStat()->addAll(0-getWeapon().getiAtk(),0-getWeapon().getiDef(),0-getWeapon().getiMaxHp());
		getItemList()->at(index) = load::getItemData(getWeapon().getID());
		if(getItemList()->at(index).getID() == 1)delItem(index);
		setWeapon(tmp.getID());
		getStat()->addAll(tmp.getiAtk(),tmp.getiDef(),tmp.getiMaxHp());
		cout << "\n\tEquipe "<<tmp.getName()<<endl;
	}else if(tmp.getItemType() == "ARMOR"){
		getStat()->addAll(0-getArmor().getiAtk(),0-getArmor().getiDef(),0-getArmor().getiMaxHp());
		getItemList()->at(index) = load::getItemData(getArmor().getID());
		if(getItemList()->at(index).getID() == 2)delItem(index);
		setArmor(tmp.getID());
		getStat()->addAll(tmp.getiAtk(),tmp.getiDef(),tmp.getiMaxHp());
		cout << "\n\tEquipe "<<tmp.getName()<<endl;
	}else if(tmp.getItemType() == "CONSUMABLE"){
		getStat()->addAll(tmp.getiAtk(),tmp.getiDef(),tmp.getiMaxHp());
		getStat()->addHp(tmp.getiHp());
		delItem(index);
		cout << "\tUse "<<tmp.getName()<<endl;
	}else{
		cout << "\n\tCannot use "<<tmp.getName()<<endl;
	}
	getch();
}

int player::countItem(int id){
	int c=0;
	for(int i=0;i<getItemList()->size();i++){
		if(getItemList()->at(i).getID() == id){
			c++;
		}
	}
	return c;
}







