#ifndef HEADER_H
#define HEADER_H

#include "marker.h"

#include "status.h"
#include "item.h"
#include "skill.h"
#include "passive.h"
#include "attack.h"
#include "monster.h"
#include "place.h"
#include "player.h"
#include "GAME.h"
#include "utility.h"
#include "battle.h"

extern vector<Item> itemData;
extern vector<monster> monsterData;
extern vector<skill> skillData;
extern vector<passive> passiveData;
extern vector<attack> attackData;
extern vector<monsterMove> monAttackData;
extern vector<Place> placeData;

extern GAME* core;
extern battle* Battle;

#endif
