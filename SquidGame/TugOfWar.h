//
// Created by baciv on 15.01.2022.
//

#ifndef SQUIDGAME_TUGOFWAR_H
#define SQUIDGAME_TUGOFWAR_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Users.h"
#include "Contenders.h"
#include "Supervisors.h"
#include "Game.h"
#include "RedLightGreenLight.h"
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>

class TugOfWar : public Game {

private:
    int group1[15];
    int group2[15];
    int group3[15];
    int group4[15];
    int maxGroupMembers;

public:
    TugOfWar(){

    }

    ~TugOfWar(void);

    void groupContenders(int x);
    void groupElimination(int group[]);
    //void groupStruggle(int group1[], int group2[]);
    void startGame();
};


#endif //SQUIDGAME_TUGOFWAR_H
