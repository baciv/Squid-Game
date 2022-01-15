//
// Created by baciv on 15.01.2022.
//

#ifndef SQUIDGAME_PRIZE_H
#define SQUIDGAME_PRIZE_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Users.h"
#include "Contenders.h"
#include "Supervisors.h"
#include "RedLightGreenLight.h"
#include "TugOfWar.h"
#include "Marbles.h"
#include "Genken.h"
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>

using namespace std;

extern vector<Users> listOfUsers;
extern vector<Supervisors> listOfSupervisors;
extern vector<Contenders> listOfContenders;

// Template method which show us the prize a user receives.

template <typename T>
void showPrize(T var){



}

template<>
void showPrize<Supervisors>(Supervisors supervisor){

    supervisor.setSupervisorPrize(supervisor.getDebt() * 10);
    cout << "The winning contestant's supervisor received the amount: " << supervisor.getSupervisorPrize() << "$." << endl;

}

template<>
void showPrize<Contenders>(Contenders contender){

    cout << "The winning contestant received the amount: ";
    contender.getTotalPrizePool();
    cout << "$" << endl;

}

// Method that helps in ranking supervisors by earnings.

bool compareEarning(Supervisors s1, Supervisors s2){

    return (s1.getSupervisorPrize() > s2.getSupervisorPrize());

}





#endif //SQUIDGAME_PRIZE_H
