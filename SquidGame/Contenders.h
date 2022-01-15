//
// Created by baciv on 14.01.2022.
//

#ifndef SQUIDGAME_CONTENDERS_H
#define SQUIDGAME_CONTENDERS_H
#include "Users.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>

class Contenders : private Users {

private:
    string firstName;
    string lastName;
    string city;
    int debt;
    int weight;
    int contenderID;
    int teamID;

public:

    static int counterContendersID;
    static int totalPrizePool;


    Contenders(){

    }


    int getContenderID();
    string getFirstName();
    string getLastName();
    string getCity();
    int getDebt();
    int getWeight();
    int getTeamID();
    void getAllUserInfo();
    void getTotalPrizePool();

    void setContenderID(int contenderID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setCity(string city);
    void setDebt(int debt);
    void setWeight(int weight);
    void setTeamID(int teamID);

    void showAll();
    void roleAllocation();
    void teamAllocation();

    void searchByTeam();
};


#endif //SQUIDGAME_CONTENDERS_H
