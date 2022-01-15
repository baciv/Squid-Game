//
// Created by baciv on 15.01.2022.
//

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

extern vector<Contenders> listOfContenders;
extern vector<Supervisors> listOfSupervisors;
vector<Contenders> marblesWinningContenders;


int Marbles::counterFights = 0;

Marbles::~Marbles(void) {

    cout << endl << "Game Marbles is over." << endl <<
         "----------------------------------------------" << endl;

}


void Marbles::startGame() {

    cout << endl <<
         "----------------------------------------------" << endl <<
         "Game Marbles has begun." << endl << endl;

    srand(time(nullptr));

    start:
    try {

        if (listOfContenders.size() % 2 == 0)
            this->maxFightsNumber = listOfContenders.size() / 2;

        else
            throw 1;

    }

    catch (int e) {

        srand(time(nullptr));

        int nrRand = rand() % ((listOfContenders.size() - 0) + 0) + 0;

        auto pos = listOfContenders.begin() + nrRand;

        Contenders auxContender;

        auxContender.setTeamID(pos->getTeamID());
        auxContender.setWeight(pos->getWeight());
        auxContender.setDebt(pos->getDebt());
        auxContender.setLastName(pos->getLastName());
        auxContender.setFirstName(pos->getFirstName());
        auxContender.setContenderID(pos->getContenderID());
        auxContender.setCity(pos->getCity());

        marblesWinningContenders.push_back(auxContender);

        listOfContenders.erase(pos);

        this->maxFightsNumber = listOfContenders.size() / 2;

        goto start;

    }


    for (this->counterFights = 0; this->counterFights < this->maxFightsNumber; this->counterFights++) {

        chooseFighters:
        try {


            int nrRand1 = rand() % ((listOfContenders.size() - 0) + 0) + 0;
            int nrRand2 = rand() % ((listOfContenders.size() - 0) + 0) + 0;

            if (nrRand1 == nrRand2)
                throw 1;

            auto fighter1 = listOfContenders.begin() + nrRand1;
            auto fighter2 = listOfContenders.begin() + nrRand2;

            startFight:
            try {

                int fighterValue1 = rand() % 1000 + 1;
                int fighterValue2 = rand() % 1000 + 1;

                if (fighterValue1 > fighterValue2) {

                    Contenders auxContender;

                    auxContender.setTeamID(fighter1->getTeamID());
                    auxContender.setWeight(fighter1->getWeight());
                    auxContender.setDebt(fighter1->getDebt());
                    auxContender.setLastName(fighter1->getLastName());
                    auxContender.setFirstName(fighter1->getFirstName());
                    auxContender.setContenderID(fighter1->getContenderID());
                    auxContender.setCity(fighter1->getCity());

                    marblesWinningContenders.push_back(auxContender);
                    listOfContenders.erase(fighter1);

                    auxContender.setTeamID(fighter2->getTeamID());
                    auxContender.setWeight(fighter2->getWeight());
                    auxContender.setDebt(fighter2->getDebt());
                    auxContender.setLastName(fighter2->getLastName());
                    auxContender.setFirstName(fighter2->getFirstName());
                    auxContender.setContenderID(fighter2->getContenderID());
                    auxContender.setCity(fighter2->getCity());

                    for (auto j = listOfSupervisors.begin(); j != listOfSupervisors.end(); ++j) {

                        if (j->getTeamID() == fighter2->getTeamID()) {

                            j->setSupervisorPrize(j->getSupervisorPrize() + fighter2->getDebt());

                        }

                    }

                    listOfContenders.erase(fighter2);

                } else if (fighterValue1 < fighterValue2) {

                    Contenders auxContender;

                    auxContender.setTeamID(fighter2->getTeamID());
                    auxContender.setWeight(fighter2->getWeight());
                    auxContender.setDebt(fighter2->getDebt());
                    auxContender.setLastName(fighter2->getLastName());
                    auxContender.setFirstName(fighter2->getFirstName());
                    auxContender.setContenderID(fighter2->getContenderID());
                    auxContender.setCity(fighter2->getCity());

                    marblesWinningContenders.push_back(auxContender);
                    listOfContenders.erase(fighter2);

                    auxContender.setTeamID(fighter1->getTeamID());
                    auxContender.setWeight(fighter1->getWeight());
                    auxContender.setDebt(fighter1->getDebt());
                    auxContender.setLastName(fighter1->getLastName());
                    auxContender.setFirstName(fighter1->getFirstName());
                    auxContender.setContenderID(fighter1->getContenderID());
                    auxContender.setCity(fighter1->getCity());


                    for (auto j = listOfSupervisors.begin(); j != listOfSupervisors.end(); ++j) {

                        if (j->getTeamID() == fighter1->getTeamID()) {

                            j->setSupervisorPrize(j->getSupervisorPrize() + fighter1->getDebt());

                        }

                    }

                    listOfContenders.erase(fighter1);


                } else
                    throw 1;

            }

            catch (int e) {

                goto startFight;

            }

        }

        catch (int e) {

            goto chooseFighters;

        }
    }

    listOfContenders = marblesWinningContenders;

    cout << endl << endl << endl << "Cine trece mai departe: " << endl;
    for (auto k = listOfContenders.begin(); k != listOfContenders.end(); ++k)
        cout << k->getContenderID() << " ";

    cout << endl << endl << endl;
}