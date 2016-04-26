#include "utility.h"

template <class T>
void load::addData(vector<T> *data,T obj){
	data->push_back(obj);
}

vector<Item>* load::getItemData(){
	return &itemData;
}
Item load::getItemData(int itemID){
	return itemData[itemID];
}

vector<monster>* load::getMonsterData(){
	return &monsterData;
}
monster load::getMonsterData(int monID){
	return monsterData[monID];
}

vector<skill>* load::getSkillData(){
	return &skillData;
}
skill load::getSkillData(int skillID){
	return skillData[skillID];
}

vector<passive>* load::getPassiveData(){
	return &passiveData;
}
passive load::getPassiveData(int passID){
	return passiveData[passID];
}

vector<attack>* load::getAttackData(){
	return &attackData;
}
attack load::getAttackData(int attackID){
	return attackData[attackID];
}

vector<monsterMove>* load::getMonAttackData(){
	return &monAttackData;
}
monsterMove load::getMonAttackData(int monAttID){
	return monAttackData[monAttID];
}

vector<Place>* load::getPlaceData(){
	return &placeData;
}
Place load::getPlaceData(int placeID){
	return placeData[placeID];
}

void load::loadItemData(){
	ifstream src;
	src.open("data/ITEM.txt");
	string line;
	while(getline(src, line)){// .substr(0,textline.find_first_of(':'))
		if(line.substr(0,line.find_first_of('/')+1) != "/"){
			
			Item *obj = new Item();
			int id = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string name = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int SP = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int BP = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string type = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int atk = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int def = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int hp = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int max = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int attIndex = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string desc = line.substr(0,line.find_first_of('\0'));

			obj->setAll(id,name,SP,BP,type,atk,def,hp,max,attIndex,desc);
			
			load::addData(load::getItemData(),*obj);

		}
	}
}

void load::loadAttackData(){
	ifstream src;
	src.open("data/ATTACK.txt");
	string line;
	while(getline(src, line)){// .substr(0,textline.find_first_of(':'))
		if(line.substr(0,line.find_first_of('/')+1) != "/"){
		
			attack *obj = new attack();
			int id = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string name = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double DmgF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int hit = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int hitC = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int criC = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double criF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string desc = line.substr(0,line.find_first_of('\0'));

			obj->setAll(id,name,DmgF,hit,hitC,criC,criF,desc);
			
			load::addData(load::getAttackData(),*obj);
		}
	}
}

void load::loadMonsterData(){
	ifstream src;
	src.open("data/MONSTER.txt");
	string line;
	while(getline(src, line)){// .substr(0,textline.find_first_of(':'))
		if(line.substr(0,line.find_first_of('/')+1) != "/"){
		
			monster *obj = new monster();
			int id = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string name = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int atk = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int def = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int hp = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string cls = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int sk = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0')); // [x,x,],[y,y,]
			string move = line.substr(0,line.find_first_of(']')+1);
			line = line.substr(line.find_first_of(']')+2,line.find_first_of('\0')); // [y,y,]
			string drop = line.substr(0,line.find_first_of('\0'));
			
			obj->setAll(id,name,atk,def,hp,cls,sk,move,drop);
			
			load::addData(load::getMonsterData(),*obj);
		}
	}
}

void load::loadMonAttackData(){
	ifstream src;
	src.open("data/MONSTERMOVE.txt");
	string line;
	while(getline(src, line)){// .substr(0,textline.find_first_of(':'))
		if(line.substr(0,line.find_first_of('/')+1) != "/"){
		
			monsterMove *obj = new monsterMove();
			int id = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string name = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double DmgF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int hit = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int hitC = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int criC = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double criF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int mhp = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int php = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int p = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int c = atoi( line.substr(0,line.find_first_of('\0')).c_str() );

			obj->setAll(id,name,DmgF,hit,hitC,criC,criF,mhp,php,p,c);
			
			load::addData(load::getMonAttackData(),*obj);
		}
	}
}

void load::loadPlaceData(){
	ifstream src;
	src.open("data/PLACE.txt");
	string line;
	while(getline(src, line)){// .substr(0,textline.find_first_of(':'))
		if(line.substr(0,line.find_first_of('/')+1) != "/"){
		
			Place *obj = new Place();
			int id = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string name = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string type = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string dest = line.substr(0,line.find_first_of(']')+1);
			line = line.substr(line.find_first_of(']')+2,line.find_first_of('\0'));
			string mons = line.substr(0,line.find_first_of('\0'));

			obj->setAll(id,name,type,dest,mons);
			
			load::addData(load::getPlaceData(),*obj);
		}
	}
}

void load::loadSkillData(){
	ifstream src;
	src.open("data/SKILL.txt");
	string line;
	while(getline(src, line)){// .substr(0,textline.find_first_of(':'))
		if(line.substr(0,line.find_first_of('/')+1) != "/"){
		
			skill *obj = new skill();
			int id = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string name = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0')); // z,[x,x,],[y,y,]
			int dmg = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0')); // [x,x,],[y,y,]
			string mplayer = line.substr(0,line.find_first_of(']')+1);
			line = line.substr(line.find_first_of(']')+2,line.find_first_of('\0')); // [y,y,]
			string mweapon = line.substr(0,line.find_first_of(']')+1);
			line = line.substr(line.find_first_of(']')+2,line.find_first_of('\0')); // [y,y,]
			string marmor = line.substr(0,line.find_first_of(']')+1);
			line = line.substr(line.find_first_of(']')+2,line.find_first_of('\0')); // [y,y,]
			string pattack = line.substr(0,line.find_first_of(']')+1);
			line = line.substr(line.find_first_of(']')+2,line.find_first_of('\0')); // [y,y,]
			string mmonster = line.substr(0,line.find_first_of(']')+1);
			line = line.substr(line.find_first_of(']')+2,line.find_first_of('\0')); // [y,y,]
			string mmattack = line.substr(0,line.find_first_of(']')+1);
			line = line.substr(line.find_first_of(']')+2,line.find_first_of('\0'));
			int t = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int cd = atoi( line.substr(0,line.find_first_of(',')).c_str() );

			obj->setAll(id,name,dmg,mplayer,mweapon,marmor,pattack,mmonster,mmattack,t,cd);

			load::addData(load::getSkillData(),*obj);
		}
	}
}

void load::loadPassiveData(){
	ifstream src;
	src.open("data/PASSIVE.txt");
	string line;
	while(getline(src, line)){// .substr(0,textline.find_first_of(':'))
		if(line.substr(0,line.find_first_of('/')+1) != "/"){
		
			passive *obj = new passive();
			int id = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string name = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double dmgF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double mnF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double dF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double stF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double cF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int cA = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int stA = atoi( line.substr(0,line.find_first_of('\0')).c_str() );

			obj->setAll(id,name,dmgF,mnF,dF,stF,cF,cA,stA);

			load::addData(load::getPassiveData(),*obj);
		}
	}
}

void load::loadData(){
	cout <<"Now loading ItemData\n";
	load::loadItemData();
	cout <<"ItemData loading success\n\n";
	
	cout <<"Now loading AttackData\n";
	load::loadAttackData();
	cout <<"AttackData loading success\n\n";
	
	cout <<"Now loading MonsterAttackData\n";
	load::loadMonAttackData();
	cout <<"MonsterAttackData loading success\n\n";
	
	cout <<"Now loading SkillData\n";
	load::loadSkillData();
	cout <<"SkillData loading success\n\n";
	
	cout <<"Now loading MonsterData\n";
	load::loadMonsterData();
	cout <<"MonsterData loading success\n\n";
	
	cout <<"Now loading PlaceData\n";
	load::loadPlaceData();
	cout <<"PlaceData loading success\n\n";
	
	cout <<"Now loading PassiveData\n";
	load::loadPassiveData();
	cout <<"PassiveData loading success\n\n";
}

void show::clear(){
//"	cout << string(50, '\n');
	system("cls");
}

void show::printData(GAME* game){
	show::clear();
	cout<<"-----------------------------------------------------------------------------\n\n";
	cout<<setw(10)<<game->getPlayer()->getName()<<"\tGold: "<<setw(5)<<game->getPlayer()->getGold()<<"\tWeapon: "<<setw(7)<<game->getPlayer()->getWeapon().getName()<<"\tArmor: "<<setw(7)<<game->getPlayer()->getArmor().getName()<<endl;
	cout<<setw(11)<<"Place: "<<game->getPlayer()->getACode().getName()<<"\tATK: "<<setw(3)<<game->getPlayer()->getStat()->getAtk()<<"\tDEF: "<<setw(3)<<game->getPlayer()->getStat()->getDef()<<"\tHP: "<<setw(5)<<game->getPlayer()->getStat()->getHp()<<"/"<<game->getPlayer()->getStat()->getMaxhp()<<endl;
	cout<<"\n-----------------------------------------------------------------------------\n";
}

void show::printLogo(){
	show::clear();
	
	cout<<endl<<endl<<endl;
cout<<"      /$$$$$$   /$$$$$$$   /$$$$$$$$       /$$$$$$$   /$$$$$$$    /$$$$$$  "<<endl;
cout<<"     /$$__  $$ | $$__  $$ | $$_____/      | $$__  $$ | $$__  $$  /$$__  $$ "<<endl;
cout<<"    | $$  \\__/ | $$  \\ $$ | $$            | $$  \\ $$ | $$  \\ $$ | $$  \\__/ "<<endl;
cout<<"    | $$       | $$$$$$$/ | $$$$$         | $$$$$$$/ | $$$$$$$/ | $$ /$$$$ "<<endl;
cout<<"    | $$       | $$____/  | $$__/         | $$__  $$ | $$____/  | $$|_  $$ "<<endl;
cout<<"    | $$    $$ | $$       | $$            | $$  \\ $$ | $$       | $$  \\ $$ "<<endl;
cout<<"    |  $$$$$$/ | $$       | $$$$$$$$      | $$  | $$ | $$       |  $$$$$$/ "<<endl;
cout<<"     \\______/  |__/       |________/      |__/  |__/ |__/        \\______/  "<<endl;
}

void show::printOver(){
	show::clear();
	cout<<endl<<endl<<endl;

cout<<"   $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$$\\ "<<endl;
cout<<"  $$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  _____|"<<endl;
cout<<"  $$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |      "<<endl;
cout<<"  $$ |$$$$\\ $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$\\    "<<endl;
cout<<"  $$ |\\_$$ |$$  __$$ |$$ \\$$$  $$ |$$  __|   "<<endl;
cout<<"  $$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |      "<<endl;
cout<<"  \\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$$$$$$$\\ "<<endl;
cout<<"   \\______/ \\__|  \\__|\\__|     \\__|\\________|"<<endl;
cout<<"                                             "<<endl;
cout<<"                                             "<<endl;
cout<<"                                             "<<endl;
cout<<"   $$$$$$\\  $$\\    $$\\ $$$$$$$$\\ $$$$$$$\\    "<<endl;
cout<<"  $$  __$$\\ $$ |   $$ |$$  _____|$$  __$$\\  "<<endl;
cout<<"  $$ /  $$ |$$ |   $$ |$$ |      $$ |  $$ |  "<<endl;
cout<<"  $$ |  $$ |\\$$\\  $$  |$$$$$\\    $$$$$$$  |  "<<endl;
cout<<"  $$ |  $$ | \\$$\\$$  / $$  __|   $$  __$$<   "<<endl;
cout<<"  $$ |  $$ |  \\$$$  /  $$ |      $$ |  $$ |  "<<endl;
cout<<"   $$$$$$  |   \\$  /   $$$$$$$$\\ $$ |  $$ |  "<<endl;
cout<<"   \\______/     \\_/    \\________|\\__|  \\__|  "<<endl;
cout<<"                                             "<<endl;
cout<<"                                             "<<endl;
}
void show::printFight(){
	show::printData(core);
	cout<<endl<<endl<<endl;
	
cout<<"\t  $$$$$$$$\\ $$$$$$\\  $$$$$$\\  $$\\   $$\\ $$$$$$$$\\ "<<endl;
cout<<"\t  $$  _____|\\_$$  _|$$  __$$\\ $$ |  $$ |\\__$$  __|"<<endl;
cout<<"\t  $$ |        $$ |  $$ /  \\__|$$ |  $$ |   $$ |   "<<endl;
cout<<"\t  $$$$$\\      $$ |  $$ |$$$$\\ $$$$$$$$ |   $$ |   "<<endl;
cout<<"\t  $$  __|     $$ |  $$ |\\_$$ |$$  __$$ |   $$ |   "<<endl;
cout<<"\t  $$ |        $$ |  $$ |  $$ |$$ |  $$ |   $$ |   "<<endl;
cout<<"\t  $$ |      $$$$$$\\ \\$$$$$$  |$$ |  $$ |   $$ |   "<<endl;
cout<<"\t  \\__|      \\______| \\______/ \\__|  \\__|   \\__|   "<<endl;
cout<<"\t                                                  "<<endl;

}

