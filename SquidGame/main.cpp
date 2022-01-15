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


using namespace std;

extern vector<Users> listOfUsers;
extern vector<Supervisors> listOfSupervisors;

int main() {

    //srand(time(0));
    //int i = rand();
    //cout << i;

    Users user;
    user.importUsers();
    //user.getAllUserInfo();
    //user.showAll();
    //cout << endl << "Ok" << endl;

    //Contenders contender;
    //contender.roleAllocation();



    Supervisors supervisors;
    supervisors.roleAllocation();
    supervisors.showAll();

    Contenders contenders;
    contenders.roleAllocation();
    contenders.teamAllocation();
    //contenders.showAll();
    contenders.searchByTeam();

    RedLightGreenLight* rlgl = new RedLightGreenLight;
    rlgl->startGame();
    //contenders.showAll();
    delete rlgl;

    TugOfWar* tow = new TugOfWar;
    tow->startGame();
    delete tow;

    Marbles* mrbls = new Marbles;
    mrbls->startGame();
    delete mrbls;

    Genken* genken = new Genken;
    genken->startGame();
    delete genken;

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
    cout << "Vedem daca merge template:";
    cout << endl << endl;

    showPrize(contender1);

    return 0;

}
