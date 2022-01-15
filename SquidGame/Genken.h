//
// Created by baciv on 15.01.2022.
//

#ifndef SQUIDGAME_GENKEN_H
#define SQUIDGAME_GENKEN_H
#include "Marbles.h"
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


class Genken : public Game {

private:
    int maxFightsNumber;

public:

    static int counterFights;

    Genken(){

    }

    ~Genken(void);

    void startGame();
};


#endif //SQUIDGAME_GENKEN_H
