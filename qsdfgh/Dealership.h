#pragma once
#include <iostream>
#include <list>
#include "Car.h"
#include "Person.h"
#include <vector>
#include "Person.h"

using namespace std;

class Dealership
{

private:
    int mMoney;
    vector<Car> mCarsOwned;
    vector<Person> mCustomers;

public:
    Dealership();
    ~Dealership();

    vector<Person> GetCustomers();
    vector<Car> GetCarsOwned();
    int GetMoney();

    void CreatePerson();
    void CreateCar();
    void SellCarToCustomer(Person customer);
    void BuyCarFromCustomer(Person customer);

    void Menu();
};