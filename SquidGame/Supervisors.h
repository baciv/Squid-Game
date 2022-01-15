//
// Created by baciv on 14.01.2022.
//

#ifndef SQUIDGAME_SUPERVISORS_H
#define SQUIDGAME_SUPERVISORS_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Users.h"
#include "Contenders.h"
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>

class Supervisors : private Users{

private:
    string firstName;
    string lastName;
    string city;
    int debt;
    int weight;
    string mask;
    int teamID;
    int supervisorPrize;

public:

    static int counterSupervisors;
    static int counterMasks;

    Supervisors(){

    }

    string getFirstName();
    string getLastName();
    string getCity();
    int getDebt();
    int getWeight();
    string getMask();
    int getTeamID();
    int getSupervisorPrize();
    void getAllUserInfo();

    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setCity(string city);
    void setDebt(int debt);
    void setWeight(int weight);
    void setMask(string mask);
    void setTeamID(int teamID);
    void setSupervisorPrize(int supervisorPrize);

    void showAll();
    void roleAllocation();


};


#endif //SQUIDGAME_SUPERVISORS_H
