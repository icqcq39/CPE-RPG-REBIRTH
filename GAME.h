#include "head.h"

#ifndef GAME_H
#define GAME_H

class GAME{
	private:
		player PLAYER;
		int mainPt = 0;
		int subPt = 0;
		string typeName = "GAME";
		string gStatus = "OKAY";
		bool free;

	public:
		GAME();
		GAME(string);
		
		player* getPlayer();
		string getType();
		int getSubPt();
		int getMainPt();
		string getGStatus();
		bool getFree();
		
		void setSubPt(int);
		void setMainPt(int);
		void nextSubPt();
		void nextMainPt();
		void gameOver();
		void setFree(bool);
		void busy();
		void notBusy();
		void goTo(int);
		int eventCheck(int);
		void engaging();
		
		void chapter0();
		void chapter1(int);
		void chapter2(int);
		void chapter3(int);
		
		void console();
		bool start();
		
};

#endif
