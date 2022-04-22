#include "Car.h"
#include <iostream>
#include <string>

using namespace std;

Car::Car() 
{
	mBrand = "Default";
	mModel = "Default";
	mColor = Color::Default;
	mLicensePlate = "Default";
	mYear = 0;
	mMileage = 0;
	mCostValue = 0;
}

Car::Car(string brand, string model, Color color, string licensePlate, int year, int mileage, int costValue) 
{
	mBrand = brand;
	mModel = model;
	mColor = color;
	mLicensePlate = licensePlate;
	mYear = year;
	mMileage = mileage;
	mCostValue = costValue;
}


Car::~Car() {}

string Car::GetBrand() { return mBrand; }
string Car::GetModel() { return mModel; }
string Car::GetPlate() { return mLicensePlate; }

void Car::Roll(int distanceInKm) 
{
	mMileage += distanceInKm;

	cout << mBrand << " " << mModel << " (" << mLicensePlate << ") ";
	cout << " mileage is now " << mMileage << " " <<endl;
}

void Car::ChangeColor(Color newColor)
{
	if (mColor == newColor)
	{
		cout << "The car is already " << mColor << endl;
		return;
	}

	mColor = newColor;
	cout << mBrand << " " << mModel << " now has the color : " << mColor << endl;
}
