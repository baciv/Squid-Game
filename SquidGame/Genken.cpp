//
// Created by baciv on 15.01.2022.
//

#include "Genken.h"
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
vector<Contenders> genkenWinningContenders;

int Genken::counterFights = 0;

Genken::~Genken(void) {

    cout << endl << "Game Genken is over." << endl <<
         "----------------------------------------------" << endl;

}

void Genken::startGame() {

    cout << endl <<
         "----------------------------------------------" << endl <<
         "Game Genken has begun." << endl << endl;

    srand(time(nullptr));



    while (listOfContenders.size() != 1) {

        auto fighter1 = listOfContenders.end();
        auto fighter2 = listOfContenders.end() - 1;

        int nrRand1 = rand() % 3 + 1;
        int nrRand2 = rand() % 3 + 1;

        startFight:
        try{

            if(nrRand1 == 1){

                if(nrRand2 == 1)
                    throw 1;

                if(nrRand2 == 2){

                    Contenders auxContender;

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

                }

                if(nrRand2 == 3){

                    Contenders auxContender;

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


                }
            }

            if(nrRand1 == 2){

                if(nrRand2 == 1){

                    Contenders auxContender;

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

                }

                if(nrRand2 == 2)
                    throw 1;

                if(nrRand2 == 3){

                    Contenders auxContender;

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

                }

            }

            if(nrRand1 == 3){

                if(nrRand2 == 1){

                    Contenders auxContender;

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

                }

                if(nrRand2 == 2){

                    Contenders auxContender;

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

                }

                if(nrRand2 == 3)
                    throw 1;

            }

        }

        catch (int e){

            nrRand2 = rand() % 3 + 1;
            goto startFight;

        }

    }

    cout << endl << endl << endl << "Contenders who passed to the next stage: " << endl;
    for (auto k = listOfContenders.begin(); k != listOfContenders.end(); ++k)
        cout << k->getContenderID() << " ";

    cout << endl << endl << endl;

}

