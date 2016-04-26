#include "place.h"

int Place::getID(){
	return id;
}
string Place::getName(){
	return name;
}
vector<int>* Place::getDestination(){
	return &this->destinationList;
}
string Place::getType(){
	return this->typeName;
}
string Place::getPlaceType(){
	return this->placeType;
}
Place Place::getDestination(int index){
	if(index < this->getDestination()->size()){
		return load::getPlaceData(this->getDestination()->at(index));
	}else{
		return load::getPlaceData(0);
	}
}
vector<int>* Place::getMonsterList(){
	return &this->monsterList;
}

void Place::setID(int ID){
	this->id = ID;
}
void Place::setName(string name){
	this->name = name;
}
void Place::addDestination(int d){
	this->destinationList.push_back(d);
}
void Place::addMonsterList(int index){
	this->monsterList.push_back(index);
}
void Place::setPlaceType(string place){
	this->placeType = place;
}
void Place::setAll(int id,string n,string type,string dest,string mons){
	this->setID(id);
	this->setName(n);
	this->setPlaceType(type);
	
	dest = dest.substr(1,dest.find_first_of(']'));//  [x,x,x,] -> x,x,x,]
	while(dest != "]"){
		this->addDestination(atoi(dest.substr(0,dest.find_first_of(',')).c_str() ));
		dest = dest.substr(dest.find_first_of(',')+1,dest.find_first_of('\0'));
	}
	
	mons = mons.substr(1,mons.find_first_of(']'));//  [x,x,x,] -> x,x,x,]
	while(mons != "]"){
		this->addMonsterList(atoi(mons.substr(0,mons.find_first_of(',')).c_str() ));
		mons = mons.substr(mons.find_first_of(',')+1,mons.find_first_of('\0'));
	}
}

void Place::printDestinationList(){
	for(int i=0;i<this->getDestination()->size();i++){
		cout << "\n\t["<<i<<"] "<<load::getPlaceData(getDestination()->at(i)).getName()<<endl;
	}
}
