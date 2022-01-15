//
// Created by baciv on 15.01.2022.
//

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

/*template <typename T>
void showPrize(T var){



}

template<>
void showPrize<Supervisors>(Supervisors supervisor){

    supervisor.setSupervisorPrize(supervisor.getDebt() * 10);
    cout << "Supervisorul concurentului castigator a primit suma: " << supervisor.getSupervisorPrize() << "$." << endl;

}

template<>
void showPrize<Contenders>(Contenders contender){

    cout << "Concurentul castigator a primit suma: ";
    contender.getTotalPrizePool();
    cout << endl;

}

*/

