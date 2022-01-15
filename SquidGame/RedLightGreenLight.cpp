//
// Created by baciv on 15.01.2022.
//

#include "RedLightGreenLight.h"
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

using namespace std;

extern vector<Contenders> listOfContenders;
extern vector<Supervisors> listOfSupervisors;

// Game Destructor
// I gave him the use of indicating the end game

RedLightGreenLight::~RedLightGreenLight(void) {

    cout << endl << "Game Red Light Green Light is over." << endl <<
         "----------------------------------------------" << endl;

}

// Method that determines the effects of the game on contenders

void RedLightGreenLight::startGame() {

    cout << endl <<
         "----------------------------------------------" << endl <<
         "Game Red Light Green Light has begun." << endl << endl;

    cout << "The following contenders will proceed to the next stage: ";

    // Game rules: Even Number = eliminate
    //             Odd Number proceed to next stage


    for (auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i) {

        if (i->getContenderID() % 2 == 0) {


            for (auto j = listOfSupervisors.begin(); j != listOfSupervisors.end(); ++j) {

                if (j->getTeamID() == i->getTeamID()) {

                    j->setSupervisorPrize(j->getSupervisorPrize() + i->getDebt());

                }

            }

            auto pos = i;
            listOfContenders.erase(pos);


        }



    }

    cout << endl;

    for (auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i){

        i->getAllUserInfo();

    }
    cout << endl;

}


