//
// Created by baciv on 14.01.2022.
//

#include "Contenders.h"
#include "Users.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>

extern vector<Users> listOfUsers;
vector<Contenders> listOfContenders;
vector<Contenders> listOfContendersCopy;

// static int for unique conterder ID
int Contenders::counterContendersID = 1;
// static int to calculate final Prize for winner
int Contenders::totalPrizePool = 0;


// getters & setters

string Contenders::getFirstName() {

    return this->firstName;

}

int Contenders::getTeamID() {

    return this->teamID;

}

string Contenders::getLastName() {

    return this->lastName;

}

string Contenders::getCity() {

    return this->city;

}

int Contenders::getDebt() {

    return this->debt;

}

int Contenders::getWeight() {

    return this->weight;

}

int Contenders::getContenderID() {

    return this->contenderID;

}

void Contenders::getTotalPrizePool() {

    cout << this->totalPrizePool;

}

void Contenders::setFirstName(string firstName) {

    this->firstName = firstName;

}

void Contenders::setTeamID(int teamID) {

    this->teamID = teamID;

}

void Contenders::setLastName(string lastName) {

    this->lastName = lastName;

}

void Contenders::setCity(string city) {

    this->city = city;

}

void Contenders::setDebt(int debt) {

    this->debt = debt;

}

void Contenders::setWeight(int weight) {

    this->weight = weight;

}

void Contenders::setContenderID(int contenderID) {

    this->contenderID = contenderID;

}

void Contenders::getAllUserInfo() {

    cout << "[ " << "[ " << getContenderID() << " ]" << " - " << getFirstName() << " " << getLastName() << ", " << getCity()
         << ", debt: " << getDebt() << "$, weight: " << getWeight() << "kg, " << "Team: " << getTeamID() << " ]" << endl;

}

// Transform User To Conterder
// After the supervisors have been chosen, each user will be listed as a contender

void Contenders::roleAllocation() {

    for (auto i = listOfUsers.begin(); i != listOfUsers.end(); ++i) {

        Contenders contender;
        contender.setContenderID(this->counterContendersID);
        this->counterContendersID++;
        contender.setFirstName(i->getFirstName());
        contender.setLastName(i->getLastName());
        contender.setCity(i->getCity());
        contender.setDebt(i->getDebt());
        contender.setWeight(i->getWeight());

        this->totalPrizePool += contender.getDebt();

        listOfContenders.push_back(contender);

    }



}

void Contenders::showAll() {

    for (auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i) {

        i->getAllUserInfo();

    }

}

// Group contenders into teams to create a relationship between supervisor and contender
// Each team is limited to 11 members

void Contenders::teamAllocation(){

    listOfContendersCopy = listOfContenders;

    srand(time(0));

    for(int numberOfTeams = 1; numberOfTeams <= 9; numberOfTeams++){

        for(int numberOfTeamMembers = 0; numberOfTeamMembers < 11; numberOfTeamMembers++){

            int nrRand = rand() % ((listOfContendersCopy.size() - 1) + 1) + 0;

            auto position = listOfContendersCopy.begin() + nrRand;

            for(auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i){

                if(i->getContenderID() == position->getContenderID()){
                    i->setTeamID(numberOfTeams);
                }

            }

            listOfContendersCopy.erase(position);

        }

    }

}

// This method shows that the teams have been correctly made and can move on.

void Contenders::searchByTeam(){

    int j = 0;

    cout << endl << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Team allocation: " << endl;

    for (auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i) {



     if(i->teamID == 1) {
         j++;
         //i->getAllUserInfo();
         //cout << i->getContenderID() << " ";

     }

    }

    cout << endl << "Team 1: " << j << endl;
    j = 0;

    for (auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i) {

        if(i->teamID == 2)
            j++;
            //i->getAllUserInfo();
    }

    cout << "Team 2: " << j << endl;
    j = 0;

    for (auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i) {

        if(i->teamID == 3)
            j++;
            //i->getAllUserInfo();
    }

    cout << "Team 3: " << j << endl;
    j = 0;

    for (auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i) {

        if(i->teamID == 4)
            j++;
            //i->getAllUserInfo();
    }

    cout << "Team 4: " << j << endl;
    j = 0;

    for (auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i) {

        if(i->teamID == 5)
            j++;
            //i->getAllUserInfo();
    }

    cout << "Team 5: " << j << endl;
    j = 0;

    for (auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i) {

        if(i->teamID == 6)
            j++;
            //i->getAllUserInfo();
    }

    cout << "Team 6: " << j << endl;
    j = 0;

    for (auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i) {

        if(i->teamID == 7)
            j++;
            //i->getAllUserInfo();
    }

    cout << "Team 7: " << j << endl;
    j = 0;

    for (auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i) {

        if(i->teamID == 8)
            j++;
            //i->getAllUserInfo();
    }

    cout << "Team 8: " << j << endl;
    j = 0;

    for (auto i = listOfContenders.begin(); i != listOfContenders.end(); ++i) {

        if(i->teamID == 9)
            j++;
            //i->getAllUserInfo();
    }

    cout << "Team 9: " << j << endl;
    j = 0;

    cout << endl << "----------------------------------------------" << endl;

}