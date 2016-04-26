#include "GAME.h"

GAME::GAME(){
	this->PLAYER.setName("PLAYER");
	this->PLAYER.setPassive(0);
	
	this->setMainPt(1);
	this->setSubPt(1);
}
GAME::GAME(string name){
	this->PLAYER.setName(name);
	this->PLAYER.setPassive(0);
	
	this->setMainPt(1);
	this->setSubPt(1);
}

player* GAME::getPlayer(){
	return &this->PLAYER;
}
string GAME::getType(){
	return this->typeName;
}
int GAME::getMainPt(){
	return this->mainPt;
}
int GAME::getSubPt(){
	return this->subPt;
}
string GAME::getGStatus(){
	return this->gStatus;
}
bool GAME::getFree(){
	return this->free;
}

void GAME::setSubPt(int s){
	this->subPt = s;
}
void GAME::setMainPt(int m){
	this->mainPt = m;
}
void GAME::nextSubPt(){
	this->setSubPt(getSubPt()+1);
}
void GAME::nextMainPt(){
	this->setMainPt(getMainPt()+1);
}
void GAME::gameOver(){
	this->gStatus = "GAMEOVER";
	busy();
}
void GAME::setFree(bool x){
	this->free = x;
}
void GAME::busy(){
	this->setFree(false);
}
void GAME::notBusy(){
	this->setFree(true);
}


void GAME::chapter0(){
	string enter,c1,c2,name,cmd;
	show::clear();
	cout << "Once upon a time there has The kingdom was a fertile kingdom.";
	getline(cin,enter);
	cout << "The population was well happy.";
	getline(cin,enter);
	cout <<  "Everyone lived in peace." ;
	getline(cin,enter);
	cout << "Until one day The Dark Lord has appeared."; 
	getline(cin,enter);
	cout << "The peace was gone. People were in fear.";
	getline(cin,enter); 
	cout << "The invasion spead out wide.";
	getline(cin,enter);
	cout << "The people were waiting for a hero to defeat The Dark Lord.";
	getline(cin,enter);
	getline(cin,enter);
	
	show::clear();
	cout << "Your family is......\n\n";
	cout << "[1] Hunter family.\n[2] Noble family.\n[3] You live in slum with others child.\n";
	do{
		cout << "COMMAND : ";
		getline(cin,c1);
	}while(!(c1=="1" || c1=="2" || c1=="3")); 
	
	show::clear();
	cout << "You want to defeat The Dark Lord because......\n";
	
	cout << "\n[1] You want fame and money.\n[2] Your village was destroyed.Your family were killed.You want to revenge.\n[3] Your want the highest honor.\n";
	do{
		cout << "COMMAND : ";
		getline(cin,c2);
	}while(!(c2=="1" || c2=="2" || c2=="3")); 
		
	do{
		show::clear();
		cout << "What is your name?\n\n";
		do{
			cout << "COMMAND : ";
			getline(cin,name);
		}while(name.size()>=10 || name.size()==0);
		cout<<"Your name is [" << name << "] right ?\n";
		cout<<"[1] YES\n[2] NO\n";
		cout << "COMMAND : ";
		getline(cin,cmd);
	}while(cmd != "1");
	int pass;
	if((c1 == "3" && c2 == "2")||(c1 == "1" && c2 =="2"))pass = 1;
	else if((c1 == "3" && c2 == "1")||(c1 == "2" && c2 =="1"))pass = 2;
	else if((c1 == "1" && c2 == "1")||(c1 == "2" && c2 =="2"))pass = 3;
	else if(c1 == "3" && c2 == "3")pass = 4;
	else if(c1 == "1" && c2 == "3")pass = 5;
	else pass = 6;
	
	this->getPlayer()->setPassive(pass);
	this->getPlayer()->setName(name);
	
	this->setMainPt(1);
	this->setSubPt(1);
}

void GAME::chapter1(int session){
	string enter;
	switch(session){
		case 1:
			show::printData(core);
			cout << "\t3 years after The Dark Lord's invasion.";
			getline(cin,enter);
			cout << "\tAt the town\n";
			getline(cin,enter);
			cout << "\t"<<PLAYER.getName() << ": Miss how much is it?";
			getline(cin,enter);
			cout << "\tMerchant: It's 30 gold";
			getline(cin,enter);
			cout << "\tTownspeople shouting.";
			getline(cin,enter);
			show::printData(core);
			cout << "\tMister A: Monsters !!";
			getline(cin,enter);
			cout << "\tMerchant: Let's escape.";
			getline(cin,enter);
			cout << "\t"<<PLAYER.getName() << ":…(Walking to monster)";
			getline(cin,enter);
			cout << "\tCentaur Leader: Kill them all and take everything.";
			getline(cin,enter);
			cout << "\tCentaur A: Hey! Why you don't run?";
			getline(cin,enter);
			cout << "\t"<<PLAYER.getName() << ": ....";
			getline(cin,enter);
			cout << "\tCentaur B: I think this guy is fear and go mad.";
			getline(cin,enter);
			cout << "\tCentaurs: Hah hah ha!";
			getline(cin,enter);
			cout << "\tChop!!";
			getline(cin,enter);
			show::printData(core);
			cout << "\tThe head of monster are flown away from their shoulder.";
			getline(cin,enter);
			cout << "\tCentaur Leader: How dare you!!";
			getline(cin,enter);
			cout << "\t"<<PLAYER.getName() << ": I will kill you all.";
			getline(cin,enter); 
			
			Battle = new battle(getPlayer(),3);
			
			busy();
			nextSubPt();
			
			break;
		case 2:
			show::printData(core);
			cout << "\tTownspeople: He can get rid of all of monsters . Who is he?";
			getline(cin,enter);
			cout << "\tLittle girl: H..Hero.";
			getline(cin,enter);
			cout << "\tPeople shouting.";
			getline(cin,enter);
			cout << "\tHero!! Hero!!";
			getline(cin,enter);
			show::printData(core);
			getline(cin,enter);
			cout << "\tChapter 1 Hero Born";
			getline(cin,enter);
			show::printData(core);
			cout << "\tMayor: Thank you for your help. If you didn't come, our town would get a lot of damage.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": I just can't let people suffered without doing anything with it.";
			getline(cin,enter);
			cout << "\tMayor: You are such a good person. We would like to reward you but sorry,\n\t at this situation we don't have enough money to use except maintain the town.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Never mind ,I just want to help.";
			getline(cin,enter);
			cout << "\tMayor: we're really thank for your help. ";
			getline(cin,enter);
			cout << "\tMister B: Mayor!";
			getline(cin,enter);
			cout << "\tMayou: What's happen?";
			getline(cin,enter);
			cout << "\tMister B: There are still soldiers who were wounded remained but we are running out of herbs.";
			getline(cin,enter);
			cout << "\tMayor: that's bad. Sir if it's not annoying you too much. Could you go to collect herbs for us?";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Okay, I will help.";
			getline(cin,enter);
			show::printData(core);
			cout << "\tQuest: Collect the herb.\n\tDetail:: Collect 5 herb from the monster in forest and send it to the mayor.";
			getline(cin,enter);
			nextSubPt();
			notBusy();
			show::clear();
			break;
		case 3:
			show::printData(core);
			cout << "\tMayor: You help us a lot. I want to give this to you. \n\tIt's not something important but keep it.";
			getline(cin,enter);
			cout << "\tYou got skill: Heal1";
			getline(cin,enter);
			show::printData(core);
			cout << "\tQuest: Go to the forest\n\tDetail: There will be something going on.";
			getline(cin,enter);
			nextSubPt();
			notBusy();
			show::clear();
			break;
		case 4:
			show::printData(core);
			cout << "\t"<< PLAYER.getName() << ":(walking in the forest)";
			getline(cin,enter);
			cout << "\tMan's sound : Help!! Somebody Help us please!!";
			getline(cin,enter);
			cout <<  "\n\tSee injured man with monster around.";
			getline(cin,enter);
			nextSubPt();
			notBusy();
			show::clear();
			break;
		case 5:
			show::printData(core);
			cout << "\t"<< PLAYER.getName() << ": Are you ok?";
			getline(cin,enter);
			cout << "\tThe man: Yes,I'm okay. But my sister cough! Cough!";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Hey!";
			getline(cin,enter);
			cout << "\tGive him a herb";
			getline(cin,enter);
			cout << "\tThe man: T..Thank.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": What happen to your sister?";
			getline(cin,enter);
			cout << "\tThe man: My s..sister was caught by the monster";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": What they caught your sister for?";
			getline(cin,enter);
			cout << "\tThe man: three year ago after The Dark Lord come.\n\tIn addition to the occupation,he caught many people who have a magic power \n\tto drain their power for increase his strength.\n\tMy sister Her power has awakened lately. she has a strong magic power but can't control it perfectly.\n\tSo we decide to go to the city to find someone \n\tthat can teach her how to control it.\n\tBut on the way we were attacked. \n\t(smash the ground) I can't do anything.(…crying)";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Do you know where they go?";
			getline(cin,enter);
			cout << "\tThe man: Huh!";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": I will help you bring her back.";
			getline(cin,enter);
			cout << "\tThe man: I heard about One of the two Knights of The Dark Lord has set up the fort in this forest.\n\tMaybe My sister was brought to there.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << "Okay let's go!!";
			getline(cin,enter);
			show::printData(core);
			cout << "\tQuest: Help the girl\n\tDetail: go to the deepest part of the forest ";
			getline(cin,enter);
			nextSubPt();
			notBusy();
			show::clear();
			break;
		case 6:
			show::printData(core);
			cout << "\tThe man: Finally we're here";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Yeah.";
			getline(cin,enter);
			cout << "\n\tOpen the gate.";
			getline(cin,enter);
			cout << "\n\tThe man: that's her.";
			getline(cin,enter);
			cout << "\n\tThe faint girl was tied with the rope at the middle of the fort";
			getline(cin,enter);
			cout << "\n\t"<< PLAYER.getName() << ": Let's get her.";
			getline(cin,enter);
			cout << "\n\tSound the ground shaking.";
			getline(cin,enter);
			show::printData(core);
			cout << "\tBehemoth: Oh! look like I have many guest come today.";
			getline(cin,enter);
			cout << "\tA big monster wearing the armor look down to us.";
			getline(cin,enter);
			cout << "\tBehemoth: What you guy come for?";
			getline(cin,enter);
			cout << "\tThe man: Give my sister back!!";
			getline(cin,enter);
			cout << "\tBehemoth: Wonderful! To help family. What an impressive story.\n\tBut I can't let that happen. This girl has a powerful magic power if My lord get this power.\n\tThere will no one in this land can against him.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Then we have to use force to bring her back.";
			getline(cin,enter);
			cout << "\tBehemoth: Oh! What a brave young men. Who are you?";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": I'm " << PLAYER.getName() << ". Remember, this is the name of the person you lost.";
			getline(cin,enter);
			cout << "\tBehemoth: Haha! Then show me your strength";
			getline(cin,enter);
			
			Battle = new battle(getPlayer(),2);
			
			busy();
			nextSubPt();
			show::clear();
			break;
		case 7:
			show::printData(core);
			cout << "\tBehemoth: argh!! You are so strong. \n\tMaybe you are someone who can defeat my lord.\n\tBut I can't let's that happen. \n\tbecause I am Behemoth the one of the two Knights. ";
			getline(cin,enter);
			cout << "\tBehemoth's body begin to emitting light";
			getline(cin,enter);
			cout << "\tThe man: That's bad he self explode. At this range we can survive.";
			getline(cin,enter);
			cout << "\t"<<  PLAYER.getName() << ": I will stop him. Argh!";
			getline(cin,enter);
			cout << "\tBehemoth: Bwah hah hah!! Die!! For my lorddddd. ";
			getline(cin,enter);
			cout << "\n\tBoooommm!!";
			getline(cin,enter);
			show::printData(core);
			cout << "\tThe man: ahhhhhhh huh! We're not died. Why?";
			getline(cin,enter);
			cout << "\t"<<  PLAYER.getName() << ": I think it's because of her";
			getline(cin,enter);
			cout << "\tIn front of us have the girl use a barrier protected us.";
			getline(cin,enter);
			cout << "\tThe man: My sis!! You save us. Are you ok? Do you have any wound.";
			getline(cin,enter);
			cout << "\tThe girl: I'm okay bro. thank you for coming to help me. And you are?";
			getline(cin,enter);
			cout << "\t"<<  PLAYER.getName() << ": I'm " << PLAYER.getName();
			getline(cin,enter);
			cout << "\tThe girl: Thank you very much. If you don't come with my brother,he will be died for sure.";
			getline(cin,enter);
			cout << "\tThe man: Hey hey!! Why you said like that? I'm your brother anyway.";
			getline(cin,enter);
			cout << "\tThe girl: But you're too weak. You can't do anything when we're attacked.";
			getline(cin,enter);
			cout << "\tThe man: Argh...";
			getline(cin,enter);
			cout << "\tThe girl: Hah hah ha";
			getline(cin,enter);
			cout << "\t"<<  PLAYER.getName() << ": Let's get out of here.";
			getline(cin,enter);
			show::printData(core);
			cout << "\tWalking.";
			getline(cin,enter);
			cout << "\n\tThe man: What do you intend to do next?";
			getline(cin,enter);
			cout << "\t"<<  PLAYER.getName() << ": My aim is kill the dark lord. Now ,The first obstacle was eliminated. \n\tI will fight for peace of all.";
			getline(cin,enter);
			cout << "\tThe man: let I go with you.\n\tI forgot to introduce myself. My name is Guitar. \n\tI'm martial art master. \n\tI can help you more or less";
			getline(cin,enter);
			cout << "\t"<<  PLAYER.getName() <<": but…";
			getline(cin,enter);
			cout << "\tGuitar: please, I can't let my sister be the target like this anymore.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << "O..Okay.";
			getline(cin,enter);
			cout << "\tGuitar: Thank.";
			getline(cin,enter);
			cout << "\tThe girl: I will go to.";
			getline(cin,enter);
			cout << "\tGuitar: It's dangerous I can't allow you to go.";
			getline(cin,enter);
			cout << "\tThe girl: but if you go who will protect me.";
			getline(cin,enter);
			cout << "\tGuitar: ugh..";
			getline(cin,enter);
			cout << "\tThe girl: Agree then. Mister " << PLAYER.getName() << " I'm Asuna nice to meet you. \n\tI'm just a trainee magician \n\tbut I think I'm useful more than my brother anyway.";
			getline(cin,enter);
			cout << "\tGuitar: Hey!!";
			getline(cin,enter);
			cout << "\tAsuna: Booo!!";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Okay, Now let's go to the next village.";
			getline(cin,enter);
			cout << "\tGuitar and Asuna: Yeahh!!";
			getline(cin,enter);
			nextMainPt();
			setSubPt(1);
			notBusy();
			show::clear();
			break;
	}
}

void GAME::chapter2(int session){
	string enter;
	switch(session){
		case 1:
			show::printData(core);
			cout << "\tChapter 2: Cursed village.";
			getline(cin,enter);
			show::printData(core);
			cout << "\tIn front of village.";
			getline(cin,enter);
			cout << "\n\tAsuna: Why This village feel so depressed.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Let's ask the villager.\n\tHey Can you tell me what's happen to this village?";
			getline(cin,enter);
			cout << "\tVillager: c….cursed this village was cursed by that's monster. \n\tIt's coming with goblins. It cursed this village. We can't do farming. \n\tThe monster went away but It left goblins around the west forest. Most of us were starving.";
			getline(cin,enter);
			cout << "\tGuitar: How we do about this?";
			getline(cin,enter);
			cout << "\tAsuna: since coming here I feel something bad from the west forest. \n\tAnd That monster left goblins around the forest like to protect something. \n\tPerhaps there might be some clues in the forest.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Yeah, If  your sense are true , It must be something in the forest.";
			getline(cin,enter);
			cout << "\tGuitar: Yeah standing here was nothing better. ";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Okay , Let's go!!";
			getline(cin,enter);
			show::printData(core);
			cout << "\tQuest: Find the clue in the forest.\n\tDetail: Go to West Forest.";
			getline(cin,enter);
			notBusy();
			nextSubPt();
			show::clear();
			break;
		case 2:
			show::printData(core);
			cout << "\tGuitar: Ughh too many goblins. I'm bored now.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Don't complain please. We feel the same as you.";
			getline(cin,enter);
			cout << "\tAsuna: Shhh Look!";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": That cave has many goblin around.";
			getline(cin,enter);
			cout << "\tAsuna: Perhaps In the cave there has something.";
			getline(cin,enter);
			show::printData(core);
			cout << "\n\tIn the cave.";
			getline(cin,enter);
			cout << "\n\tGuitar: Look like this is the end of the cave.";
			getline(cin,enter);
			cout << "\n\tA Large Crystal is located.";
			getline(cin,enter);
			cout << "\n\tGuitar:  What is this!!";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": What this crystal do.";
			getline(cin,enter);
			cout << "\tAsuna: Look like it absorb energy from this land.";
			getline(cin,enter);
			cout << "\tGuitar: This is why the land is drought. then Destroy it.";
			getline(cin,enter);
			cout << "\n\tRoarrrr!!";
			getline(cin,enter);
			show::printData(core);
			cout << "\tGuitar: What's that sound?";
			getline(cin,enter);
			cout << "\n\tThe Orc appear.";
			getline(cin,enter);
			cout << "\tAsuna: Look like this orc is the protector of the crystal.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Prepare It's coming.";
			getline(cin,enter);
			
			Battle = new battle(getPlayer(),7);
			
			nextSubPt();
			busy();
			show::clear();
			break;
		case 3:
			show::printData(core);
			cout << "\t"<< PLAYER.getName() << ": Now destroy the crystal.";
			getline(cin,enter);
			cout << "\tAsuna: Leave it to me. Explosionnnnnn!!";
			getline(cin,enter);
			cout << "\n\tBooom!!";
			getline(cin,enter);
			cout << "\n\tGuitar: The land is restoring.";
			getline(cin,enter);
			cout << "\tAt the village";
			getline(cin,enter);
			cout << "\tVillage elder: You save our village. Could you tell me your name?";
			getline(cin,enter);
			cout << "\t"<<  PLAYER.getName() << ": I'm " << PLAYER.getName();
			getline(cin,enter);
			cout << "\tVillage elder: OH! You're the hero in the rumor. Thank you so much.";
			getline(cin,enter);
			cout << "\t"<<  PLAYER.getName() << "That's fine.";
			getline(cin,enter);
			cout << "\tVillage elder: Oh yes. That monster left the message to you.";
			getline(cin,enter);
			cout << "\t"<<  PLAYER.getName() << ": What is the message ?";
			getline(cin,enter);
			cout << "\tVillage elder: Hero I will waiting for you at my fortress on west land.\n\tIf you don't come, next time it will not just be a curse.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": What is that monster name?";
			getline(cin,enter);
			cout << "\tVillage elder: It told it's one of two knight of the dark lord.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": I will go. You two don't come. Their target this time was me. Here is safer.";
			getline(cin,enter);
			cout << "\tGuitar: But..";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Please.";
			getline(cin,enter);
			cout << "\tAsuna: You must not die. Promise me.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": I promise.";
			getline(cin,enter);
			show::printData(core);
			cout << "\tQuest: Defeat The One of Two Knight.\n\tDetail: Go to Westland";
			getline(cin,enter);
			nextSubPt();
			notBusy();
			show::clear();
			break;
		case 4:
			show::printData(core);
			cout << "\tAt the boss's room";
			getline(cin,enter);
			cout << "\n\tApocalypse: Welcome hero.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": You are?";
			getline(cin,enter);
			cout << "\tApocalypse: I'm Apocalypse one of two knights. Although Two knights have just only me left now.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Why you call me here?";
			getline(cin,enter);
			cout << "\tApocalypse: I heard you can defeat behemoth. \n\tSo I call you for invite you to be one of two knight instead of him. \n\tIf you are one of us. You will get everything after our lord dominate this world. \n\tIs it sound interesting?";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Yes, but I will get everything I want after you all are eliminated. ";
			getline(cin,enter);
			cout << "\tApocalypse: What a shame.";
			getline(cin,enter);
			
			Battle = new battle(getPlayer(),8);
			
			nextSubPt();
			busy();
			show::clear();
			break;
		case 5:
			show::printData(core);
			cout << "\tApocalypse: No Doubt that you can beat the behemoth. I will show you my true power.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": What's that";
			getline(cin,enter);
			cout << "\tA lot of crystal are appeared.";
			getline(cin,enter);
			cout << "\tApocalypse: All of this crystal was absorbing energy from many land. I will use this energy as my power.";
			getline(cin,enter);
			cout << "\tBwah hah hah!!";
			getline(cin,enter);
			cout << "\tApocalypse: Nobody can beat me now.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Urgh.. (how can I beat him?) ";
			getline(cin,enter);
			cout << "\n\tHave a light from the crystal to Hero.";
			getline(cin,enter);
			show::printData(core);
			cout << "\t"<< PLAYER.getName() << ": What happen to my body. Look like the power from crystals is sent to me too.";
			getline(cin,enter);
			cout << "\tApocalypse: now die!!";
			getline(cin,enter);
			cout << "\tYahhhh!!";
			getline(cin,enter);
			cout << "\tApocalypse: W..what a power?";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": You told this was your power but it's not. This's power of the land . \n\tIt's power for everyone not just for you. \n\tTime to end this!!\n\tYahhhh!!";
			getline(cin,enter);
			cout << "\n\tApocalypse was cut into 2 parts.";
			getline(cin,enter);
			cout << "\n\tApocalypse: unbelievable….";
			getline(cin,enter);
			cout << "\n\tThe body of Apocalypse is disappered.";
			getline(cin,enter);
			show::printData(core);
			cout << "\t"<< PLAYER.getName() << ": I need to destroy the crystal to bring the energy back to where it should be.\n\tHah!!";
			getline(cin,enter);
			cout << "\tSome of Energy are going into Hero's body.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Now only the dark lord left. Waiting for me.";
			getline(cin,enter);
			show::printData(core);
			cout << "\tYou got skill: Excaribur.";
			getline(cin,enter);
			show::printData(core);
			cout << "\tGo back to the village.";
			getline(cin,enter);
			cout << "\n\tGuitar: Are you ok?";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Yes, I'm okay.";
			getline(cin,enter);
			cout << "\tAsuna: You are safe. Thank God.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() <<": Sorry for making you worried.";
			getline(cin,enter);
			show::printData(core);
			cout << "\tGuitar: It's time to go.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Okay.";
			getline(cin,enter);
			cout << "\tVillage elder:  Wait a minute. Please bring this with you. This is the sacred item of our village.";
			getline(cin,enter);
			show::printData(core);
			cout << "\tYou got Holy stone.";
			getline(cin,enter);
			show::printData(core);
			cout << "\t"<< PLAYER.getName() << ": Thank you. we're going now .";
			getline(cin,enter);
			show::printData(core);
			cout << "\tQuest:Go to The dark lord's castle.\n\tDetail: Go to the place next to the west land.";
			getline(cin,enter);
			nextMainPt();
			setSubPt(1);
			show::clear();
			break;
	}
}

void GAME::chapter3(int session){
	string enter;
	switch(session){
		case 1:
			show::printData(core);
			cout << "\tIn front of a military camp.";
			getline(cin,enter);
			cout << "\n\t"<< PLAYER.getName() << ": Hello we want to pass the camp. Can you open the door?";
			getline(cin,enter);
			cout << "\n\tThe gate open and a lot of soldier are coming out.";
			getline(cin,enter);
			cout << "\n\tSoldiers: #@$%^*&";
			getline(cin,enter);
			cout << "\tGuitar: Hah hah ha! Why They look unfriendly?";
			getline(cin,enter);
			cout << "\tAsuna: It looks like they are in control.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": They are coming. Prepare! ";
			getline(cin,enter);
			
			Battle = new battle(getPlayer(), 9);
			
			nextSubPt();
			busy();
			show::clear();
			break;
		case 2:
			show::printData(core);
			cout << "\tHoly Stone emit light.";
			getline(cin,enter);
			cout << "\tCommander: Arghhh…What happen to us. We remember we're fighting the dark lord why we are here?";
			getline(cin,enter);
			cout << "\tAsuna: You all were controlled.";
			getline(cin,enter);
			cout << "\tCommander:  If that Thank you very much for help us. you are?";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": I'm " << PLAYER.getName() << " We're taking an adventure for defeat the dark lord.";
			getline(cin,enter);
			cout << "\tCommander: Oh you're the hero that save the village.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Can you lead me to the dark lord place?";
			getline(cin,enter);
			cout << "\tCommander: Sure. Waiting me for prepare my army. We will go when we're ready. ";
			getline(cin,enter);
			show::printData(core);
			cout << "\tQuest: Defeat The Dark Lord\n\tDetail: Talk with the commander.";
			getline(cin,enter);
			nextSubPt();
			busy();
			show::clear();
			break;
		case 3:
			show::printData(core);
			cout << "\tAsuna: Bro I can feel something bad. I worry something will happen to you.";
			getline(cin,enter);
			cout << "\tGuitar: Don't worry Asuna. my duty is protect you. I will not leave you alone. \n\tAnd we have P come with us everything will be okay.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Yes,Don't worry too much.";
			getline(cin,enter);
			cout << "\tAsuna: Umm.";
			getline(cin,enter);
			cout << "\tCommander: Okay we're ready. Let's go.";
			getline(cin,enter);
			cout << "\tSoldiers: Ohhhhhhh!!";
			getline(cin,enter);
			nextSubPt();
			notBusy();
			show::clear();
			break;
		case 4:
			show::printData(core);
			cout << "\tAt the dark lord castle.";
			getline(cin,enter);
			cout << "\n\t"<< PLAYER.getName() << ": There have too many the dark lord's minions.";
			getline(cin,enter);
			cout << "\tCommander: Leave them to us. Let's go ahead.";
			getline(cin,enter);
			nextSubPt();
			notBusy();
			show::clear();
			break;
		case 5:
			show::printData(core);
			cout << "\tAt the top of castle.";
			getline(cin,enter);
			cout << "\n\tThe Dark Lord AJK: Finally you're coming hero.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": It's time to pay back for everything you steal from everyone.";
			getline(cin,enter);
			cout << "\tThe Dark Lord AJK: Hah hah ha I don't stop stealing. I will get everything and this girl too.";
			getline(cin,enter);
			cout << "\tGuitar: Asuna!!";
			getline(cin,enter);
			cout << "\tGuitar jump to the magic.";
			getline(cin,enter);
			cout << "\tGuitar: Argh..";
			getline(cin,enter);
			cout << "\tAsuna: Brotherrr You'll be alright. I will heal you now.(crying)";
			getline(cin,enter);
			cout << "\tGuitar: It's no use. you can't heal this much wound. ";
			getline(cin,enter);
			cout << "\tAsuna: Bro..(crying)";
			getline(cin,enter);
			cout << "\tGuitar: "<< PLAYER.getName() <<  " take care my sister please.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Okay.";
			getline(cin,enter);
			cout << "\tGuitar: don't let her be harm. Promise me.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": I swear.";
			getline(cin,enter);
			cout << "\tGuitar: Thank…….";
			getline(cin,enter);
			cout << "\tAsuna: Brotherrrrrrrr!!!";
			getline(cin,enter);
			cout << "\tThe Dark Lord AJK: Bwah hah hah!! What a weak.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": You're bastard.";
			getline(cin,enter);
			cout << "\n\tDieeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
			getline(cin,enter);
			
			Battle = new battle(getPlayer(),15);
			
			nextSubPt();
			busy();
			show::clear();
			break;
		case 6:
			show::printData(core);
			cout << "\tThe Dark Lord AJK: Not bad! Take this! My Finish move. Dark Bane!!!!!";
			getline(cin,enter);
			cout << "\tAsuna: Grab my hand I will send you my power.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << " and Asuna grab their hand and Their bodies begin to emit light.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << " and Asuna: Take This! Holy final finisher Sword!!!!!!";
			getline(cin,enter);
			cout << "\tThe Dark Lord AJK: what's this power! Arghhhhhh!!";
			getline(cin,enter);
			cout << "\tBody of The Dark Lord AJK is disappeared.";
			getline(cin,enter);
			show::printData(core);
			cout << "\t"<< PLAYER.getName() << ": It's end now.";
			getline(cin,enter);
			cout << "\tAsuna: Yes.";
			getline(cin,enter);
			cout << "\n\tThe castle is shaking.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": What happen!!";
			getline(cin,enter);
			cout << "\tThe Dark Lord AJK sound : Bwah hah hah Although I lost, but you had to die too. \n\tI left my mind in this castle. This castle will be exploded in 3 minute. \n\tDie all. Bwah hah hah!!";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() <<": It seems every soldier's getting out now.";
			getline(cin,enter);
			cout << "\tAsuna: We need to run too.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": That's impossible. It must have someone control the power of explosion. \n\tIf not everyone will die anyway.";
			getline(cin,enter);
			cout << "\tAsuna: If that I will..";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": No! I will be the one who live here. I swear to your brother that will not let you die. ";
			getline(cin,enter);
			cout << "\tAsuna: but..";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Take this. Look like this holy stone have a power to teleport you to the safe place.";
			getline(cin,enter);
			cout << "\tAsuna: ..." << PLAYER.getName() << "..I love you.";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": ……Thank I love you too.";
			getline(cin,enter);
			cout << "\tAsuna: (crying)";
			getline(cin,enter);
			cout << "\t"<< PLAYER.getName() << ": Go now!!";
			getline(cin,enter);
			cout << "\tAsuna is teleported.";
			getline(cin,enter);
			show::printData(core);
			cout << "\tThe dark lord's castle was exploded.";
			getline(cin,enter);
			cout << "\tAnd The hero was disappered.";
			getline(cin,enter);
			cout << "\tThe Story of Hero become a Legend Forever.";
			getline(cin,enter);
			show::printData(core);
			cout << "\tFin.";
			getline(cin,enter);
			nextMainPt();
			setSubPt(1);
			show::clear();
		}
}

