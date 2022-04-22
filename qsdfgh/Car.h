#pragma once
#include <iostream>
#include <string>
#include "Color.h"

using namespace std;

class Car
{
	/*3. Create the Car class :
		A car has : A brand, a model, a color, a license plate, a year, a mileage(number of miles since
			construction), and a cost value
		A car can : Roll some amount of miles, Change color*/

private :
	string mBrand;
	string mModel;
	Color mColor;
	string mLicensePlate;
	int mYear;
	int mMileage;
	int mCostValue;

public :
	Car();
	Car(string mBrand,
		string mModel,
		Color mColor,
		string mLicensePlate,
		int mYear,
		int mMileage,
		int mCostValue);
	~Car();

	string GetBrand();
	string GetModel();
	string GetPlate();

	void Roll(int distanceInKm);
	void ChangeColor(Color newColor);
};

