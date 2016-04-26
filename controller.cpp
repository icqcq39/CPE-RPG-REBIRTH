#include "GAME.h"

void GAME::console(){
	string cmd="";
	int c=0;
		cout <<"\t"<<"Choose your action.\n";
		cout <<"\t"<<"[1] INVENTORY\n";
		cout <<"\t"<<"[2] SKILL\n";
		cout <<"\t"<<"[3] GO TO\n\n";
		while(cmd != "6969"){
			do{
				cout <<"\t"<<"COMMAND: ";
				getline(cin,cmd);
			}while(!(cmd == "1" || cmd == "2" || cmd == "3"));
			
			if(cmd=="1") {
				cout<<endl;
				show::printData(core);
				getPlayer()->showItemList();
				do{
					cout <<"\t"<<"COMMAND: ";
					getline(cin,cmd);
				}while(!(atoi(cmd.c_str()) < getPlayer()->getItemList()->size() && atoi(cmd.c_str()) >=0));
				getPlayer()->use(atoi(cmd.c_str()));
				cmd = "6969";	
			}
			else if(cmd=="2") {
				cout<<endl;
				if(!getPlayer()->showSkillList())cout << "\tYou have no skill.\n";
				getch();
				cmd = "6969";
			}else if(cmd=="3") {
				cout<<endl;
				show::printData(core);
				getPlayer()->getACode().printDestinationList();
				do{
					cout <<"\n\tCOMMAND: ";
					getline(cin,cmd);
				}while(!(atoi(cmd.c_str()) < getPlayer()->getACode().getDestination()->size() && atoi(cmd.c_str()) >=0));
				this->goTo(getPlayer()->getACode().getDestination()->at(atoi(cmd.c_str())));
				cmd = "6969";
			}
		}
}

void GAME::goTo(int dest){
	int path = eventCheck(dest);
	if(path != 0){
		getPlayer()->setACode(dest);
		cout << "You are going to "<<load::getPlaceData(dest).getName()<<endl;
	}else{
		cout << "You cant go to "<<load::getPlaceData(dest).getName()<<endl;
	}
	if(path==1){
		this->engaging();
	}
	getch();
}

int GAME::eventCheck(int dest){
	int mp = getMainPt();
	int sp = getSubPt();
	if(mp == 1){
		if(dest == 6)return 0;
		if(dest == 5){
			if(sp < 6)return 0;
		}
		if(dest == 1){
			if(sp == 3){
				if(getPlayer()->countItem(5) >= 5){
					getPlayer()->delItem(5,5);
					busy();
					return -1;
				}
			}
		}
		if(dest == 2){
			if(sp == 4){
				busy();
				return -1;
			}
		}
		if(dest == 3){
			if(sp == 5){
				busy();
				return -1;
			}
		}
		if(dest == 5){
			if(sp == 6){
				busy();
				return -1;
			}
		}
	}
	if(mp == 2){
		if(dest == 12){
			if(sp < 4)return 0;
		}
		if(dest == 14){
			return 0;
		}
		if(dest == 1){
			if(sp == 2){
				busy();
				return -1;
			}
		}
		if(dest == 6){
			busy();
			return -1;
		}
		if(dest == 13){
			busy();
			return -1;
		}
	}
	if(mp == 3){
		if(dest == 15){
			if(sp == 4){
				busy();
				return -1;
			}
		}
		if(dest == 28){
			if(sp == 5){
				busy();
				return -1;
			}
		}
	}
	return 1;
}

void GAME::engaging(){
	if(getPlayer()->getACode().getPlaceType() == "DUNGEON"){
		int n = getPlayer()->getACode().getMonsterList()->size();
		n = rand()%n;
		Battle = new battle(getPlayer(),getPlayer()->getACode().getMonsterList()->at(n));
	}
}
