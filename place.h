#include "head.h"
#ifndef PLACE_H
#define PLACE_H

class Place{
	public:
		int getID();
		string getName();
		vector<int>* getDestination();
		string getType();
		string getPlaceType();
		Place getDestination(int);
		vector<int>* getMonsterList();
		
		void setID(int);
		void setName(string);
		void addDestination(int);
		void addMonsterList(int);
		void setPlaceType(string);
		void setAll(int,string,string,string,string);
		void printDestinationList();
		
	private:
		string typeName = "PLACE";
		int id;
		string name;
		string placeType; //TOWN, DUNGEON, SHOP, ROOM
		vector<int> destinationList;
		vector<int> monsterList;
};

#endif


