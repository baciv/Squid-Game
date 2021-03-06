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
#include "Prize.h"
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <bits/stdc++.h>


using namespace std;

extern vector<Users> listOfUsers;
extern vector<Supervisors> listOfSupervisors;

int main() {

    // Import users from Database


    Users user;
    user.importUsers();


    // Transform users into supervisors and contenders.


    Supervisors supervisors;
    supervisors.roleAllocation();
    supervisors.showAll();

    Contenders contenders;
    contenders.roleAllocation();
    contenders.teamAllocation();
    contenders.searchByTeam();

    // Red Light Green Light Game

    RedLightGreenLight* rlgl = new RedLightGreenLight;
    rlgl->startGame();
    delete rlgl;

    // Tug Of War Game

    TugOfWar* tow = new TugOfWar;
    tow->startGame();
    delete tow;

    // Marbles Game

    Marbles* mrbls = new Marbles;
    mrbls->startGame();
    delete mrbls;

    // Genken Game

    Genken* genken = new Genken;
    genken->startGame();
    delete genken;

    // Show the biggest Winner of Squid Game

    Contenders contender1;

    auto k = listOfContenders.begin();

    contender1.setCity(k->getCity());
    contender1.setContenderID(k->getContenderID());
    contender1.setFirstName(k->getFirstName());
    contender1.setLastName(k->getLastName());
    contender1.setDebt(k->getDebt());
    contender1.setWeight(k->getWeight());
    contender1.setTeamID(k->getTeamID());

    cout << endl << endl;
    cout << "The Big Winner is: ";
    contender1.getAllUserInfo();
    cout << endl << endl;

    showPrize(contender1);

    sort(listOfSupervisors.begin(), listOfSupervisors.end(), compareEarning);

    int circleEarnings = 0;
    int triangleEarnings = 0;
    int rectangularEarnings = 0;
    int ok = 0;

    cout << "Supervisors earnings: ";
    cout << endl << endl;
    for(auto k = listOfSupervisors.begin(); k != listOfSupervisors.end(); ++k){

        cout << k->getFirstName() << " " << k->getLastName() << ": " << k->getSupervisorPrize() << "$" << endl;

        if(k->getMask() == "Circle"){
            circleEarnings += k->getSupervisorPrize();
            ok = 1;
        }


        if(k->getMask() == "Triangle"){
            triangleEarnings += k->getSupervisorPrize();
            ok = 2;
        }


        if(k->getMask() == "Rectangular"){
            rectangularEarnings += k->getSupervisorPrize();
            ok = 3;
        }


    }


    int teamWithMostEarnings = max({circleEarnings, triangleEarnings, rectangularEarnings});

    cout << endl << endl;
    if(ok == 1)
        cout << "The team with the most earnings is  Circle: " << teamWithMostEarnings << "$";
    if(ok == 2)
        cout << "The team with the most earnings is  Triangle: " << teamWithMostEarnings << "$";
    if(ok == 3)
        cout << "The team with the most earnings is  Rectangular: " << teamWithMostEarnings << "$";
    cout << endl << endl;


    return 0;

}
