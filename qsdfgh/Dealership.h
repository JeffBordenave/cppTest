#pragma once
#include <iostream>
#include <list>
#include "Car.h"
#include "Person.h"
#include <vector>

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

    void CreatePerson();
    void CreateCar();
    void SellCarToCustomer();
    void BuyCarFromCustomer();
};