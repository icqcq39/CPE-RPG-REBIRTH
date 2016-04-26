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
	if(dest == 16|| dest == 19||dest == 22){
		this->SAVE();
	}
	if(dest == 17|| dest == 20||dest == 23){
		this->SHOP();
	}
	if(dest == 18|| dest == 21||dest == 24){
		this->HOSPITAL();
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

bool GAME::start(){
	string cmd ="";
	show::printLogo();
	
	cout<<endl<<endl<<endl;
	cout<<"\t[1]  Start a new game\n\n";
	cout<<"\t[2]  Load game\n\n\n";
	do{
		cout<<"\tCOMMAND: ";
		getline(cin,cmd);
	}while(!(cmd == "1"||cmd =="2"));
	
	return true;
}

void GAME::SHOP(){
	string cmd;
	show::printData(core);
	cout<<"\tWelcome ,Would you like to BUY or SELL\n\n";
	do{
		cout<<"\t[1]  BUY\n\n";
		cout<<"\t[2]  SELL\n\n\n";
		do{
			cout<<"\tCOMMAND: ";
			getline(cin,cmd);
		}while(!(cmd == "1"||cmd =="2"));
		if(cmd=="1"){
			this->BUY();
		}else{
			this->SELL();
		}
		show::printData(core);
		cout <<"\n\tDo you want to do any things else?\n\n";
		cout<<"\t[1]  YES\n\n";
		cout<<"\t[2]  NO, THANKS\n\n\n";
		cout<<"\tCOMMAND: ";
		getline(cin,cmd);
		show::printData(core);
	}while(!(cmd =="2"));
	show::printData(core);
	cout<<"\tThanks for coming.\n";
	getch();
}
void GAME::SAVE(){
	
}
void GAME::HOSPITAL(){
	
}
void GAME::BUY(){
	string cmd;
	
	do{
		show::printData(core);
		cout<<"\tWhat do you want to BUY.\n\n";
		cout<<endl;
		load::getShopDataByPlace(getPlayer()->getACode().getID()).printSellList();
		do{
			cout<<"\tCOMMAND: ";
			getline(cin,cmd);
		}while(!( atoi(cmd.c_str()) >= 0 && atoi(cmd.c_str()) < load::getShopDataByPlace(getPlayer()->getACode().getID()).getSellList()->size()) );
		show::printData(core);
		if(getPlayer()->getGold() >= load::getShopDataByPlace(getPlayer()->getACode().getID()).getSellList()->at(atoi(cmd.c_str())).getPB()){
			cout<<"\tYou have bought "<< load::getShopDataByPlace(getPlayer()->getACode().getID()).getSellList()->at(atoi(cmd.c_str())).getName()<<"\n";
			getPlayer()->addGold(0-load::getShopDataByPlace(getPlayer()->getACode().getID()).getSellList()->at(atoi(cmd.c_str())).getPB());
			getPlayer()->addItem(load::getShopDataByPlace(getPlayer()->getACode().getID()).getSellList()->at(atoi(cmd.c_str())).getID());
		}else{
			cout << "\n\tSorry, You dont have enough money.\n";
		}
		getch();
		show::printData(core);
		cout <<"\n\tDo you want to buy any things else?\n\n";
		cout<<"\t[1]  YES\n\n";
		cout<<"\t[2]  NO, THANKS\n\n\n";
		cout<<"\tCOMMAND: ";
		getline(cin,cmd);
		show::printData(core);
	}while(!(cmd =="2"));
	show::printData(core);
	getch();
}
void GAME::SELL(){
		string cmd;
		int iItem=0;
	
	do{
		if(getPlayer()->getItemList()->size() != 0){
		show::printData(core);
		cout<<"\tWhat do you want to SELL.\n\n";
		cout<<endl;
		getPlayer()->showItemList();
		do{
			cout<<"\tCOMMAND: ";
			getline(cin,cmd);
		}while(!( atoi(cmd.c_str()) >= 0 && atoi(cmd.c_str()) < getPlayer()->getItemList()->size()) );
		show::printData(core);
		iItem = atoi(cmd.c_str());
		cout<<"\n\tAre you sure to sell "<<getPlayer()->getItemList()->at(iItem).getName()<<"?\n";
		cout<<"\t[1]  YES\n\n";
		cout<<"\t[2]  NO No.\n\n\n";
		do{
			cout<<"\tCOMMAND: ";
			getline(cin,cmd);
		}while(!( cmd=="1"||cmd=="2"));
		if(cmd =="1"){
			getPlayer()->setGold(getPlayer()->getItemList()->at(iItem).getPS());
			cout << "\n\tYou got "<<getPlayer()->getItemList()->at(iItem).getPS()<<" Golds. From selling "<<getPlayer()->getItemList()->at(iItem).getName()<<"\t";
			getPlayer()->delItem(iItem);
			getch();
		}
		}else{
			cout<<"\n\tYou have nothing to sell.\n";
			getch();
		}
		show::printData(core);
		cout <<"\tDo you want to sell any things else?\n\n";
		cout<<"\t[1]  YES\n\n";
		cout<<"\t[2]  NO, THANKS\n\n\n";
		cout<<"\tCOMMAND: ";
		getline(cin,cmd);
		show::printData(core);
	}while(!(cmd =="2"));
	show::printData(core);
}
