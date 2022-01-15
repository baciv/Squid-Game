//
// Created by george_cosmin.baciu on 14.01.2022.
//

// This class is for imput.

#ifndef SQUIDGAME_USERS_H
#define SQUIDGAME_USERS_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Users {

private:
    string firstName;
    string lastName;
    string city;
    int debt;
    int weight;
    int teamID;

public:
    Users(){

    }

    Users(string firstName, string lastName, string city,
          int debt, int weight);


    string getFirstName();
    string getLastName();
    string getCity();
    int getDebt();
    int getWeight();
    void getAllUserInfo();

    void setFirstName(string firstName);
    void setLastName();
    void setCity();
    void setDebt();
    void setWeight();

    void importUsers();
    void roleAllocation();
    void showAll();

};


#endif //SQUIDGAME_USERS_H
