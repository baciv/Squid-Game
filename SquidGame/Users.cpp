//
// Created by george_cosmin.baciu on 14.01.2022.
//

#include "Users.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>

using namespace std;


vector<Users> listOfUsers;


Users::Users(string firstName, string lastName, string city,
             int debt, int weigth) {



    this->firstName = firstName;
    this->lastName = lastName;
    this->city = city;
    this->debt = debt;
    this->weight = weigth;

}

// import function
void Users::importUsers() {

    // from JSON file

    ifstream file("DatabaseOfUsers.json");
    Json::Value actualJson;
    Json::Reader reader;
    int i;

    reader.parse(file, actualJson);
    srand(time(nullptr));

    // save all data from Database as Users objects

    for(i = 0; i < actualJson.size(); i++){



        string firstNameRead = actualJson[i]["firstName"].asString();
        string lastNameRead = actualJson[i]["lastName"].asString();
        string cityRead = actualJson[i]["city"].asString();


        int debtRead = rand() % ((100000 - 10000) + 1) + 10000;
        int weigthRead = rand() % ((100 - 50) + 1) + 50;



        Users user(firstNameRead, lastNameRead, cityRead, debtRead, weigthRead);


        listOfUsers.push_back(user);
    }


}

// getters & setters

string Users::getFirstName() {

    return this->firstName;

}

string Users::getLastName() {

    return this->lastName;

}

string Users::getCity() {

    return this->city;

}

int Users::getDebt() {

    return this->debt;

}

int Users::getWeight() {

    return this->weight;

}

void Users::getAllUserInfo() {

    cout << "[ " << getFirstName() << " " << getLastName() << ", " << getCity()
    << ", debt: " << getDebt() << "$, " << getWeight() << "kg ]" << endl;

}

void Users::showAll() {

    for (auto i = listOfUsers.begin(); i != listOfUsers.end(); ++i) {

        i->getAllUserInfo();

    }

}


