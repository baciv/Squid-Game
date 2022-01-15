//
// Created by baciv on 15.01.2022.
//

#ifndef SQUIDGAME_REDLIGHTGREENLIGHT_H
#define SQUIDGAME_REDLIGHTGREENLIGHT_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Users.h"
#include "Contenders.h"
#include "Supervisors.h"
#include "Game.h"
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>

class RedLightGreenLight : public Game {

public:
    void startGame();
    ~RedLightGreenLight();
};


#endif //SQUIDGAME_REDLIGHTGREENLIGHT_H
