#include "battle.h"

battle::battle(player* p,int m){
	this->setPlayer(p);
	this->setEnemy(m);
	this->setTurn(1);
	this->setBanTurn(0);
	this->setPSkill(0);this->setESkill(0);
	this->setPassive(getPlayer()->getPassive().getID());
	this->getMonster()->getStat()->setHp(getMonster()->getStat()->getMaxhp());
	this->setEAtack(*(getMonster()->getAttackMove()));
	if(getPASSIVE().getName() == "BRAVER"){
		getPlayer()->getStat()->addAll(getPASSIVE().getStatAdd(),getPASSIVE().getStatAdd(),getPASSIVE().getStatAdd());
		getPlayer()->getStat()->setHp(getPlayer()->getStat()->getMaxhp());
	}
	if(getPASSIVE().getName() == "ARROGANCE"){
		getPlayer()->getStat()->addAll(getPlayer()->getWeapon().getiAtk() * getPASSIVE().getStatFactor(), getPlayer()->getWeapon().getiDef() * getPASSIVE().getStatFactor(), getPlayer()->getWeapon().getiMaxHp() * getPASSIVE().getStatFactor());
		getPlayer()->getStat()->setHp(getPlayer()->getStat()->getMaxhp());
	}
	show::printFight();
	getch();
	this->fight();
}

string battle::getType(){
	return this->typeName;
}
player* battle::getPlayer(){
	return this->PLAYER;
}
monster* battle::getMonster(){
	return &this->ENEMY;
}
int battle::getPFinalDmg(){
	return this->pFinalDmg;
}
int battle::getEFinalDmg(){
	return this->eFinalDmg;
}
vector<monsterMove>* battle::getEAttack(){
	return &this->eAttack;
}
int battle::getGold(){
	return this->goldReward;
}
skill battle::getPSkill(){
	return this->pSkill;
}
skill battle::getESkill(){
	return this->eSkill;
}
int battle::getTurn(){
	return this->turn;
}
monsterMove battle::getEMove(){
	return this->eMove;
}
int battle::getBanTurn(){
	return this->banTurn;
}
bool battle::isOnban(){
	if(getBanTurn()>getTurn()){
		return true;
	}
	return false;
}
passive battle::getPASSIVE(){
	return this->PASSIVE;
}
int battle::getPhpCon(monsterMove move){
	return ((getPlayer()->getStat()->getMaxhp() * move.getPlayerHpBelow()) / 100);
}
int battle::getEhpCon(monsterMove move){
	return ((getMonster()->getStat()->getMaxhp() * move.getMonHpBelow()) / 100);
}
int battle::getPSkillT(){
	return this->pSkillT;
}
int battle::getESkillT(){
	return this->eSkillT;
}

void battle::setPlayer(player* pt){
	this->PLAYER = pt;
}
void battle::setEnemy(int index){
	this->ENEMY = load::getMonsterData(index);
}
void battle::setPassive(int index){
	this->PASSIVE = load::getPassiveData(index);
}
void battle::setPFinalDmg(int dmg){
	this->pFinalDmg = dmg;
}
void battle::setEFinalDmg(int dmg){
	this->eFinalDmg = dmg;
}
void battle::setEAtack(vector<monsterMove> vec){
	this->eAttack = vec;
}
void battle::setGold(int gold){
	this->goldReward = gold;
}
void battle::setPSkill(int i){
	this->pSkill = load::getSkillData(i);
}
void battle::setESkill(int i){
	this->eSkill = load::getSkillData(i);
}
void battle::setTurn(int t){
	this->turn = t;
}
void battle::setEMove(int i){
	this->eMove = load::getMonAttackData(i);
}
void battle::setBanTurn(int b){
	this->banTurn = b;
}
void battle::onCD(int n){
	this->setBanTurn(this->getTurn()+(2*n));
}
void battle::setPSkillT(int p){
	if(p<0)p=0;
	this->pSkillT = p;
}
void battle::setESkillT(int e){
	if(e<0)e=0;
	this->eSkillT = e;
}

int battle::calcPDmg(){
	double tmp = 0;
	int patk = this->getPlayer()->getStat()->getAtk() + this->getPSkill().getModPlayer(0) + this->getESkill().getModPlayer(0);
	int edef = this->getMonster()->getStat()->getDef() + this->getPSkill().getModMonster(1) + this->getESkill().getModMonster(1);
	tmp = pow(patk,2) / (patk + edef);
	
	if(isCri()){
		tmp = tmp * this->getPSkill().getModPlayerAttack(4) * this->getESkill().getModPlayerAttack(4) * this->getPlayer()->getAttack().getCriFactor();
		if(getPASSIVE().getName() == "HUNTER"){
			tmp *= getPASSIVE().getCriFactor();
		}
	}
	
	tmp = tmp * this->getPSkill().getModPlayerAttack(0) * this->getESkill().getModPlayerAttack(0) * this->getPlayer()->getAttack().getDmgFactor();
	
	if(getPASSIVE().getName() == "PRIDE"){
		tmp *= getPASSIVE().getDmgFactor();
	}
	if(getPASSIVE().getName() == "REVENGER" && (getPlayer()->getStat()->getHp() < 5)){
		tmp *= getPASSIVE().getDmgFactor();
	}
	return tmp;
}
int battle::calcEDmg(attack move){
	double tmp = 0;
	int pdef = this->getPlayer()->getStat()->getDef() + this->getPSkill().getModPlayer(1) + this->getESkill().getModPlayer(1);
	int eatk = this->getMonster()->getStat()->getAtk() + this->getPSkill().getModMonster(0) + this->getESkill().getModMonster(0);
	
	tmp = pow(eatk,2) / (eatk + pdef);
	if(isCri()){
		tmp = tmp * this->getPSkill().getModMonsterAttack(4) * this->getESkill().getModMonsterAttack(4) * move.getCriFactor();
	}

	tmp = tmp * this->getPSkill().getModMonsterAttack(0) * this->getESkill().getModMonsterAttack(0) * move.getDmgFactor();

	return tmp;
}
bool battle::isCri(){
	int value = this->getPlayer()->getAttack().getCriChance() + this->getPSkill().getModPlayerAttack(3) + this->getESkill().getModPlayerAttack(3);
	if(getPASSIVE().getName() == "HUNTER"){
		value += getPASSIVE().getCriChanceAdd();
	}
	if(value > 100)value = 100;
	else if(value < 0)value = 0;
	if(value >= (rand()%100 +1)){
		return true;
	}else{
		return false;
	}
}
bool battle::isHit(){
	int value = this->getPlayer()->getAttack().getHitChance() + this->getPSkill().getModPlayerAttack(2) + this->getESkill().getModPlayerAttack(2);
	if(value > 100)value = 100;
	else if(value < 0)value = 0;
	
	if(value >= (rand()%100 +1)){
		return true;
	}else{
		return false;
	}
}
void battle::battleScene(monsterMove move){
	show::printData(core);
	cout <<setw(27)<<"ENEMY"<<" TURN  :  "<< this->getTurn() <<endl<<endl;
	cout <<setw(33)<<this->getMonster()->getName()<<"  ["<<this->getMonster()->getStat()->getHp()<<"/"<<this->getMonster()->getStat()->getMaxhp()<<"]\n\n";
	cout <<setw(35)<<move.getName()<<endl<<endl;
}
void battle::battleScene(skill smove){
	show::printData(core);
	cout <<setw(27)<<"ENEMY"<<" TURN  :  "<< this->getTurn() <<endl<<endl;
	cout <<setw(33)<<this->getMonster()->getName()<<"  ["<<this->getMonster()->getStat()->getHp()<<"/"<<this->getMonster()->getStat()->getMaxhp()<<"]\n\n";
	cout <<setw(35)<<"---------{"<<smove.getName()<<"}---------"<<endl;
	cout <<setw(44)<<"{ACTIVATION}"<<endl<<endl;
}
void battle::battleScene(){
	show::printData(core);
	cout <<setw(27)<<"YOUR TURN  :  "<< this->getTurn() <<endl<<endl;
	cout <<setw(33)<<this->getMonster()->getName()<<"  ["<<this->getMonster()->getStat()->getHp()<<"/"<<this->getMonster()->getStat()->getMaxhp()<<"]\n\n";
	cout <<endl;
}
void battle::console(){
	string cmd="";
	int c=0;
		cout <<"\t"<<"Choose your action.\n";
		cout <<"\t"<<"[1] ATTACK\n";
		cout <<"\t"<<"[2] ITEM\n";
		cout <<"\t"<<"[3] SKILL\n\n";
		while(cmd != "6969"){
			do{
				cout <<"\t"<<"COMMAND: ";
				getline(cin,cmd);
			}while(!(cmd == "1" || cmd == "2" || cmd == "3" || cmd == "4"));
			
			if(cmd=="1") {
				this->pattack();
				cmd = "6969";	
			}
			else if(cmd=="2") {
				if(this->getPlayer()->showItemList("CONSUMABLE")){
					cout <<"Which item do you want\n";
					do{
						cout <<"COMMAND: ";	
						cin>>c;
					}while(!useItem(c));
					cmd = "6969";
				}
			}else if(cmd=="3") {
				if(!isOnban()){
					if(this->getPlayer()->showSkillList()){
						do{
							cout <<"COMMAND: ";	
							getline(cin,cmd);
							cin>>c;
						}while(!useSkill(c));
						cmd = "6969";
					}
				}else{
					cout<<"On cooldown\n";
				}
			}
		}
}

void battle::pattack(){
	this->battleScene();
	for(int i=0;i<this->getPlayer()->getAttack().getHitNumber();i++){
		if(isHit()){
			this->setPFinalDmg(calcPDmg());
			this->getMonster()->getStat()->takeDamage(getPFinalDmg());
			
			cout << "\tEnemy took damage "<<getPFinalDmg()<<" points\n";
		
		}else{

			cout << "\tMISS\n";
		}
		getch();
	}
}
bool battle::useItem(int index){
	if(load::getItemData(index).getItemType() == "CONSUMABLE"){
		this->getPlayer()->getStat()->addAll(load::getItemData(index).getiAtk(),load::getItemData(index).getiDef(),load::getItemData(index).getiMaxHp());
		this->getPlayer()->getStat()->addHp(load::getItemData(index).getiHp());
		this->getPlayer()->delItem(index);
		return true;
	}
	return false;
}
bool battle::useSkill(int index){
	if(index>0 && index<this->getPlayer()->getSkillList()->size()){
		this->setPSkill(this->getPlayer()->getSkillList()->at(index).getID());
		this->onCD(this->getPSkill().getCooldown());
		this->setPSkillT(this->getPSkill().getCooldown()*2+1);
		return true;
	}
	return false;
}
void battle::useMonSkill(){
	this->setESkill(getMonster()->getMonSkill().getID());
	this->setESkillT(getESkill().getTurn()*2+1);
}

void battle::fight(){
	do{
		myTurn();
		if(!nextTurn())break;
		enemyTurn();
	}while(nextTurn());
	battleScene();
	if(getMonster()->getStat()->getHp()==0){
		cout <<"\t CONGRATULATION You Win.\n";
		getch();
		endBattle();
	}else{
		cout <<"\t You Died.\n";
		core->gameOver();
	}
	
}
void battle::myTurn(){
	battleScene();
	console();
}
void battle::enemyTurn(){
	if(checkHeat() && getESkillT()==0){
		this->useMonSkill();
		battleScene(getESkill());
	}else{
		emoveSelect();
		this->setEFinalDmg(calcEDmg(getEMove()));
		this->getPlayer()->getStat()->takeDamage(getEFinalDmg());
		battleScene(getEMove());
		getch();
		cout << "\tYou take damages " <<getEFinalDmg()<<" points\n";
	}
	
	
	getch();
}
void battle::emoveSelect(){
	int pHp = this->getPlayer()->getStat()->getHp();
	int eHp = this->getMonster()->getStat()->getHp();
	int pool = 0;
	
	for(int i=0;i< this->getMonster()->getAttackMove()->size();i++ ){
		pool += this->getMonster()->getAttackMove()->at(i).getChance();
	}
	for(int j = 0;j<3;j++){
		int pick = rand() % pool + 1;
		for(int i=0;i< this->getMonster()->getAttackMove()->size();i++ ){
			if(pick <= this->getMonster()->getAttackMove()->at(i).getChance()){
				if(checkHpCon(this->getMonster()->getAttackMove()->at(i))){
					this->setEMove(this->getMonster()->getAttackMove()->at(i).getID());  //result here
					break;
				}else{
					pick += this->getMonster()->getAttackMove()->at(i).getChance();
				}
			}else{
				pick -= this->getMonster()->getAttackMove()->at(i).getChance();
			}
		}	
	}
}
bool battle::checkHpCon(monsterMove move){
	if((getPhpCon(move) >= this->getPlayer()->getStat()->getHp()) && (getEhpCon(move) >= this->getMonster()->getStat()->getHp())){
		return true;
	}else{
		return false;
	}
}
bool battle::checkHeat(){
	static bool chFlag = true;
	if(((this->getMonster()->getStat()->getMaxhp()/2) > this->getMonster()->getStat()->getHp()) && chFlag &&getMonster()->getMonSkill().getID() != 0){
		if(rand()%100+1 < 33){
			chFlag = false;
			return true;	
		}
	}
	return false;
}
bool battle::nextTurn(){
	this->updateSkill();
	this->setTurn(getTurn()+1);
	if(getPlayer()->getStat()->getHp()==0 || getMonster()->getStat()->getHp()==0)return false;
	else return true;
}
void battle::revertPSkill(){
	cout << "\t Player : "<<getPSkill().getName()<<" effect were off\n";
	this->setPSkill(0);
	getch();
}
void battle::revertESkill(){
	cout <<"\t Enemy : "<< getESkill().getName()<<" effect were off\n";
	this->setESkill(0);
	getch();
}
void battle::updateSkill(){
	this->setPSkillT(getPSkillT()-1);
	this->setESkillT(getESkillT()-1);
	if(getPSkillT()==0 && getPSkill().getID()!=0){
		this->revertPSkill();
	}
	if(getESkillT() == 0 && getESkill().getID()!=0){
		this->revertESkill();
	}
}
void battle::endBattle(){
	if(getPASSIVE().getName() == "BRAVER"){
		getPlayer()->getStat()->addAll(0-getPASSIVE().getStatAdd(),0-getPASSIVE().getStatAdd(),0-getPASSIVE().getStatAdd());
		getPlayer()->getStat()->setHp(getPlayer()->getStat()->getMaxhp());
	}
	if(getPASSIVE().getName() == "ARROGANCE"){
		getPlayer()->getStat()->addAll(0-getPlayer()->getWeapon().getiAtk() * getPASSIVE().getStatFactor(), 0-getPlayer()->getWeapon().getiDef() * getPASSIVE().getStatFactor(), 0-getPlayer()->getWeapon().getiMaxHp() * getPASSIVE().getStatFactor());
		getPlayer()->getStat()->setHp(getPlayer()->getStat()->getMaxhp());
	}
	show::printData(core);
	bool flag = true;
	for(int i=0;i<getMonster()->getDropList()->size();i++){
		if(this->takeDrop(getMonster()->getDropList()->at(i))){
			flag = false;
		}
	}
	if(flag){
		cout<<"\t You got nothing from "<<getMonster()->getName()<<endl;
	}
	getch();
	this->takeGold();
	getPlayer()->addGold(getGold());
	show::printData(core);
	cout << "\tYou got money from "<<getMonster()->getName()<<" ["<<getGold()<<"]\n";
	getch();
}
int battle::dropCtran(string str){
	return atoi( str.substr(str.find_first_of(':')+1,str.find_first_of('\0')).c_str());
}
int battle::dropIDtran(string str){
	return atoi( str.substr(0,str.find_first_of(':')).c_str());
}
bool battle::takeDrop(string str){
	int chance = dropCtran(str);
	if(getPASSIVE().getName() == "AMBITIONS"){
		chance *= getPASSIVE().getDropFactor();
	}
	if(rand()%100+1 < chance){
		getPlayer()->addItem(dropIDtran(str));
		cout << "\tYou got "<< load::getItemData(dropIDtran(str)).getName() <<" from "<<getMonster()->getName()<<endl;
		return true;
	}
	return false;
}
void battle::takeGold(){
	//COMMON, RARE, MINIBOSS, BOSS
	string cls = getMonster()->getClass();
	int base;
	if(cls == "COMMON")base = (rand()%5);
	else if(cls == "RARE")base = (rand()%100)+200;
	else if(cls == "MINIBOSS")base = (rand()%100+100);
	else if(cls == "BOSS")base = (rand()%200+300);
	
	if(getPASSIVE().getName() == "AMBITIONS"){
		base *= getPASSIVE().getMoneyFactor();
	}
	
	this->setGold(base);
}
