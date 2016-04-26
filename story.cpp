#include "story.h"

//void Story::Walker(){
//	chapter(getCM(),getCS());//cm0cs0
//	clear();
//	nextCS();
//	chapter(getCM(),getCS());//cm0cs1
//	clear();
//	nextCS();
//	chapter(getCM(),getCS());//cm0cs2
//	clear();
//	nextCS();
//	chapter(getCM(),getCS());//cm0cs3
//	clear();
//	nextCM();
//	setCS(0); // chapter 0
//}

int Story::chapter(int cm,int cs){
	string enter;
	switch(cm){
		case 0:
			switch(cs){
				case 0:
					cout << "Once upon a time there has The kingdom was a fertile kingdom.";
					getline(cin,enter);
					cout << "The population was well happy.";
					getline(cin,enter);
					cout <<  "Everyone lived in peace ." ;
					getline(cin,enter);
					cout << "Until one day The Dark Lord has appeared."; 
					getline(cin,enter);
					cout << "The peace was gone. People were in fear.";
					getline(cin,enter); 
					cout << "The invasion spead out wide.";
					getline(cin,enter);
					cout << "The people were waiting for a hero to defeat The Dark Lord. "; 
					break;
				case 1:
					cout << "Your family is......";
					getline(cin,enter);
					cout << "[1] Hunter family.\n[2] Noble family.\n[3] You live in slum with others child.";
					do{
						cin >> enter;
					}while(enter!="1" || enter!="2" || enter!="3");
					return atoi(enter.c_str());
				case 2:
					cout << "You want to defeat The Dark Lord because......";
					getline(cin,enter);
					cout << "[1] You want fame and money.\n[2] Your village was destroyed.Your family were killed.You want to revenge.\n[3] Your want the highest honor.";
					do{
						cin >> enter;
					}while(enter!="1" || enter!="2" || enter!="3");
					return atoi(enter.c_str());
				case 3:
					cout << "What is your name? ";
					cin >> enter;
					//return 0;
			}
			break;
		case 1:
			switch(cs){
				case 0:
					cout << "";
			}
			break;
	}
}

int Story::getCM(){
	return this->CM;
}

int Story::getCS(){
	return this->CS;
}

void Story::setCM(int cm){
	this->CM = cm;
}

void Story::setCS(int cs){
	this->CS = cs;
}

void Story::nextCM(){
	setCM(getCM()+1);
}

void Story::nextCS(){
	setCS(getCS()+1);
}

void Story::clear(){
	cout << string(50, '\n');
}

Story::Story(){
	setCM(0);
	setCS(0);
}
