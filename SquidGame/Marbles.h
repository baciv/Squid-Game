//
// Created by baciv on 15.01.2022.
//

#ifndef SQUIDGAME_MARBLES_H
#define SQUIDGAME_MARBLES_H
#include "TugOfWar.h"
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

class Marbles : public Game {

private:
    int maxFightsNumber;

public:

    static int counterFights;

    Marbles(){

    }

    ~Marbles();

    void startGame();
    void eliminateContender(Contenders contender);


};


#endif //SQUIDGAME_MARBLES_H
