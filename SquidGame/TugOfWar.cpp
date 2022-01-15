//
// Created by baciv on 15.01.2022.
//

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
vector<Contenders> winningContenders;
vector<Contenders> listOfContendersCopy1;


TugOfWar::~TugOfWar(void) {

    cout << endl << "Game Tug Of War is over." << endl <<
         "----------------------------------------------" << endl;

}


void TugOfWar::groupContenders(int x) {

    this->maxGroupMembers = x / 4;
    int groupWeight = 0;

    srand(time(nullptr));
    listOfContendersCopy1 = listOfContenders;

    cout << endl << "1239182391283123901238129038129038" << endl;
    for(auto k = listOfContendersCopy1.begin(); k != listOfContendersCopy1.end(); ++k)
        k->getAllUserInfo();
    cout << endl << "1239182391283123901238129038129038" << endl;

    for(int i = 0; i < this->maxGroupMembers; i++){

        int nrRand = rand() % ((listOfContendersCopy1.size() - 1) + 1) + 0;

        auto pos = listOfContendersCopy1.begin() + nrRand;

        this->group1[i] = pos->getContenderID();

        groupWeight += pos->getWeight();

        listOfContendersCopy1.erase(pos);

    }

    this->group1[this->maxGroupMembers] = groupWeight;
    groupWeight = 0;

    cout << endl << endl << "~~!@!@#!#@!#!#!#@~~" << endl;
    cout << "1. Contenders without group: ";
    for(auto k = listOfContendersCopy1.begin(); k != listOfContendersCopy1.end(); ++k)
        k->getAllUserInfo();
    cout << endl << listOfContendersCopy1.size() << endl;

    for(int i = 0; i < this->maxGroupMembers; i++){

        int nrRand = rand() % ((listOfContendersCopy1.size() - 1) + 1) + 0;

        auto pos = listOfContendersCopy1.begin() + nrRand;

        this->group2[i] = pos->getContenderID();

        groupWeight += pos->getWeight();

        listOfContendersCopy1.erase(pos);

    }

    this->group2[this->maxGroupMembers] = groupWeight;
    groupWeight = 0;

    cout << endl << endl << "~~!@!@#!#@!#!#!#@~~" << endl;
    cout << "2. Contenders without group: ";
    for(auto k = listOfContendersCopy1.begin(); k != listOfContendersCopy1.end(); ++k)
        k->getAllUserInfo();
    cout << endl << listOfContendersCopy1.size() << endl;

    for(int i = 0; i < this->maxGroupMembers; i++){

        int nrRand = rand() % ((listOfContendersCopy1.size() - 1) + 1) + 0;

        auto pos = listOfContendersCopy1.begin() + nrRand;

        this->group3[i] = pos->getContenderID();

        groupWeight += pos->getWeight();

        listOfContendersCopy1.erase(pos);

    }

    this->group3[this->maxGroupMembers] = groupWeight;
    groupWeight = 0;

    cout << endl << endl << "~~!@!@#!#@!#!#!#@~~" << endl;
    cout << "3. Contenders without group: ";
    for(auto k = listOfContendersCopy1.begin(); k != listOfContendersCopy1.end(); ++k)
        k->getAllUserInfo();
    cout << endl << listOfContendersCopy1.size() << endl;

    for(int i = 0; i < this->maxGroupMembers; i++){

        int nrRand = rand() % ((listOfContendersCopy1.size() - 1) + 1) + 0;

        auto pos = listOfContendersCopy1.begin() + nrRand;

        this->group4[i] = pos->getContenderID();

        groupWeight += pos->getWeight();

        listOfContendersCopy1.erase(pos);

    }

    this->group4[this->maxGroupMembers] = groupWeight;
    groupWeight = 0;

    cout << endl << endl << "~~!@!@#!#@!#!#!#@~~" << endl;
    cout << "4. Contenders without group: ";
    for(auto k = listOfContendersCopy1.begin(); k != listOfContendersCopy1.end(); ++k)
        k->getAllUserInfo();
    cout << endl << listOfContendersCopy1.size() << endl;

    cout << endl << endl << "~~!@!@#!#@!#!#!#@~~" << endl;
    cout << "Group1: ";
    for(int i = 0; i <= this->maxGroupMembers; i++)
        cout << this->group1[i] << " ";


    cout << endl << endl << "~~!@!@#!#@!#!#!#@~~" << endl;
    cout << "Group2: ";
    for(int i = 0; i <= this->maxGroupMembers; i++)
        cout << this->group2[i] << " ";


    cout << endl << endl << "~~!@!@#!#@!#!#!#@~~" << endl;
    cout << "Group3: ";
    for(int i = 0; i <= this->maxGroupMembers; i++)
        cout << this->group3[i] << " ";


    cout << endl << endl << "~~!@!@#!#@!#!#!#@~~" << endl;
    cout << "Group4: ";
    for(int i = 0; i <= this->maxGroupMembers; i++)
        cout << this->group4[i] << " ";


    cout << endl;

}

void TugOfWar::groupElimination(int *group) {

    for(int i = 0; i < this->maxGroupMembers; i++){

        auto pos = listOfContenders.begin();

        for(auto k = listOfContenders.begin(); k != listOfContenders.end(); ++k){

            if(group[i] == k->getContenderID())
                pos = k;

        }


        for (auto j = listOfSupervisors.begin(); j != listOfSupervisors.end(); ++j) {

            if (j->getTeamID() == pos->getTeamID()) {

                j->setSupervisorPrize(j->getSupervisorPrize() + pos->getDebt());

            }

        }

        listOfContenders.erase(pos);

    }

}


void TugOfWar::startGame() {

    cout << endl <<
         "----------------------------------------------" << endl <<
         "Game Tug Of War has begun." << endl << endl;

    try {

        int isEgality = 1;
        if (listOfContenders.size() % 4 == 0)
            groupContenders(listOfContenders.size());

        else {
            isEgality = 0;
            throw isEgality;
        }

    }

    catch (int e) {

        cout << endl << "listOfContenders.size(): " << listOfContenders.size() << endl;

        Contenders auxContender;

        srand(time(nullptr));

        while (listOfContenders.size() % 4 != 0) {

            int nrRand = rand() % ((listOfContenders.size() - 0) + 0) + 0;

            auto pos = listOfContenders.begin() + nrRand;

            auxContender.setTeamID(pos->getTeamID());
            auxContender.setWeight(pos->getWeight());
            auxContender.setDebt(pos->getDebt());
            auxContender.setLastName(pos->getLastName());
            auxContender.setFirstName(pos->getFirstName());
            auxContender.setContenderID(pos->getContenderID());
            auxContender.setCity(pos->getCity());

            winningContenders.push_back(auxContender);
            listOfContenders.erase(pos);

        }

        cout << endl << endl << "~~!@!@#!#@!#!#!#@~~" << endl;
        cout << "Winners: ";
        for (auto k = winningContenders.begin(); k != winningContenders.end(); ++k)
            cout << k->getContenderID() << " ";

        cout << endl << endl << "~~!@!@#!#@!#!#!#@~~" << endl;
        cout << "Contenders remains: ";
        auxContender.showAll();

        groupContenders(listOfContenders.size());

    }

    //groupStruggle(this->group1, this->group2);

    //cout << endl << endl << endl << "Test eliminare buna: " << endl;
    //for(auto k = listOfContenders.begin(); k != listOfContenders.end(); ++k)
    //    cout << k->getContenderID() << " ";

    //cout << endl << endl << endl;


    int winner1 = 0;
    int winner2 = 0;


    if (this->group1[this->maxGroupMembers] > this->group2[this->maxGroupMembers]) {
        groupElimination(this->group2);
        winner1 = 1;
    } else if (this->group1[this->maxGroupMembers] < this->group2[this->maxGroupMembers]) {
        groupElimination(this->group1);
        winner1 = 2;
    }

    if (this->group3[this->maxGroupMembers] > this->group4[this->maxGroupMembers]) {
        groupElimination(this->group4);
        winner2 = 3;
    } else if (this->group3[this->maxGroupMembers] < this->group4[this->maxGroupMembers]) {
        groupElimination(this->group3);
        winner2 = 4;
    }

    if (winner1 == 1 && winner2 == 3) {
        if (this->group1[this->maxGroupMembers] > this->group3[this->maxGroupMembers]) {
            groupElimination(this->group3);
        } else if (this->group1[this->maxGroupMembers] < this->group3[this->maxGroupMembers]) {
            groupElimination(this->group1);
        }
    }

    if (winner1 == 1 && winner2 == 4) {
        if (this->group1[this->maxGroupMembers] > this->group4[this->maxGroupMembers]) {
            groupElimination(this->group4);
        } else if (this->group1[this->maxGroupMembers] < this->group4[this->maxGroupMembers]) {
            groupElimination(this->group1);
        }
    }

    if (winner1 == 2 && winner2 == 4) {
        if (this->group2[this->maxGroupMembers] > this->group4[this->maxGroupMembers]) {
            groupElimination(this->group4);
        } else if (this->group2[this->maxGroupMembers] < this->group4[this->maxGroupMembers]) {
            groupElimination(this->group2);
        }
    }

    if (winner1 == 2 && winner2 == 3) {
        if (this->group2[this->maxGroupMembers] > this->group3[this->maxGroupMembers]) {
            groupElimination(this->group3);
        } else if (this->group2[this->maxGroupMembers] < this->group3[this->maxGroupMembers]) {
            groupElimination(this->group2);
        }
    }

    cout << endl << endl << endl << "Test eliminare buna: " << endl;
    for(auto k = listOfContenders.begin(); k != listOfContenders.end(); ++k)
        cout << k->getContenderID() << " ";

    cout << endl << endl << endl;

    for(auto k = winningContenders.begin(); k != winningContenders.end(); ++k){

        Contenders auxContender;

        auxContender.setTeamID(k->getTeamID());
        auxContender.setWeight(k->getWeight());
        auxContender.setDebt(k->getDebt());
        auxContender.setLastName(k->getLastName());
        auxContender.setFirstName(k->getFirstName());
        auxContender.setContenderID(k->getContenderID());
        auxContender.setCity(k->getCity());

        listOfContenders.push_back(auxContender);

    }

    cout << endl << endl << endl << "Cine trece mai departe: " << endl;
    for(auto k = listOfContenders.begin(); k != listOfContenders.end(); ++k)
        cout << k->getContenderID() << " ";

    cout << endl << endl << endl;

}


