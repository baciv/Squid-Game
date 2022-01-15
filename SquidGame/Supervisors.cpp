//
// Created by baciv on 14.01.2022.
//

#include "Supervisors.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Users.h"
#include "Contenders.h"
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>


extern vector<Users> listOfUsers;
vector<Supervisors> listOfSupervisors;


string Supervisors::getFirstName() {

    return this->firstName;

}

string Supervisors::getLastName() {

    return this->lastName;

}

string Supervisors::getCity() {

    return this->city;

}

int Supervisors::getDebt() {

    return this->debt;

}

int Supervisors::getWeight() {

    return this->weight;

}

string Supervisors::getMask() {

    return this->mask;

}

void Supervisors::setFirstName(string firstName) {

    this->firstName = firstName;

}

void Supervisors::setLastName(string lastName) {

    this->lastName = lastName;

}

void Supervisors::setCity(string city) {

    this->city = city;

}

void Supervisors::setDebt(int debt) {

    this->debt = debt;

}

void Supervisors::setWeight(int weight) {

    this->weight = weight;

}

void Supervisors::setMask(string mask) {

    this->mask = mask;

}

void Supervisors::setTeamID(int teamID) {

    this->teamID = teamID;

}

int Supervisors::getTeamID() {

    return this->teamID;

}

void Supervisors::setSupervisorPrize(int supervisorPrize) {

    this->supervisorPrize = supervisorPrize;

}

int Supervisors::getSupervisorPrize() {

    return this->supervisorPrize;

}

void Supervisors::getAllUserInfo() {

    cout << "[ " << getMask() << " - " << getFirstName() << " " << getLastName() << ", " << getCity()
         << ", debt: " << getDebt() << "$, weight: " << getWeight() << "kg, " << "Team: " << getTeamID() << " ]" << endl;

}

void Supervisors::showAll() {

    for (auto i = listOfSupervisors.begin(); i != listOfSupervisors.end(); ++i) {

        i->getAllUserInfo();

    }

}


int Supervisors::counterSupervisors = 1;
int Supervisors::counterMasks = 1;



void Supervisors::roleAllocation() {

    srand(time(nullptr));

    for(this->counterSupervisors = 1; this->counterSupervisors <= 9; this->counterSupervisors++) {

        int nrRand;

        nrRand = rand() % ((listOfUsers.size() - 0) + 0) + 0;


        auto position = listOfUsers.begin() + nrRand;

        for (auto i = listOfUsers.begin(); i != listOfUsers.end(); ++i) {


            if(i == position){

                Supervisors supervisors;

                supervisors.setTeamID(counterSupervisors);
                supervisors.setFirstName(i->getFirstName());
                supervisors.setLastName((i->getLastName()));
                supervisors.setCity(i->getCity());
                supervisors.setDebt(i->getDebt());
                supervisors.setWeight(i->getWeight());
                supervisors.setSupervisorPrize(-supervisors.getDebt());

                if(this->counterMasks <= 3)
                    supervisors.setMask("Rectangular");
                else
                if(this->counterMasks <= 6)
                    supervisors.setMask("Triangle");
                else
                    supervisors.setMask("Circle");


                this->counterMasks++;
                listOfSupervisors.push_back(supervisors);

                listOfUsers.erase(position);

            }

        }


    }

}

