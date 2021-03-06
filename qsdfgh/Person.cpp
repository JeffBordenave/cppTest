#include "Person.h"
#include <iostream>

Person::Person()
{
	mFirstName = "Default";
	mLastName = "Default";
	mGender = Gender::DefGender;
	mDayOfBirth = 0;
	mMonthOfBirth = 0;
	mYearOfBirth = 0;
	mMoney = 0;
	mHasCar = false;
}

Person::Person(std::string firstName, std::string lastName)
{
	mFirstName = firstName;
	mLastName = lastName;
}

Person::Person(std::string firstName, std::string lastName, Gender gender)
{
	mFirstName = firstName;
	mLastName = lastName;
	mGender = gender;
}

Person::Person(std::string firstName, std::string lastName, Gender gender, int dayOfBirth, int monthOfBirth, int yearOfBirth)
{
	mFirstName = firstName;
	mLastName = lastName;
	mGender = gender;
	mDayOfBirth = dayOfBirth;
	mMonthOfBirth = monthOfBirth;
	mYearOfBirth = yearOfBirth;
}

Person::Person(std::string firstName, std::string lastName, Gender gender, int dayOfBirth, int monthOfBirth, int yearOfBirth, int money)
{
	mFirstName = firstName;
	mLastName = lastName;
	mGender = gender;
	mDayOfBirth = dayOfBirth;
	mMonthOfBirth = monthOfBirth;
	mYearOfBirth = yearOfBirth;
	mMoney = money;
}

Person::Person(std::string firstName, std::string lastName, Gender gender, int dayOfBirth, int monthOfBirth, int yearOfBirth, int money, Car car)
{
	mFirstName = firstName;
	mLastName = lastName;
	mGender = gender;
	mDayOfBirth = dayOfBirth;
	mMonthOfBirth = monthOfBirth;
	mYearOfBirth = yearOfBirth;
	mMoney = money;
	mCar = car;
	mHasCar = true;;
}

Person::~Person() {}

string Person::GetName() { return mFirstName; }
bool Person::CheckHasCar() { return mHasCar; }
Car Person::GetCar() { return mCar; }
int Person::GetMoney() { return mMoney; }

void Person::IntroduceSelf()
{
	std::cout << mFirstName << " " << mLastName;
	std::cout << " was born on " << mMonthOfBirth << " " << mDayOfBirth << ", " << mYearOfBirth;
	std::cout << " and is a " << mGender << std::endl;

	std::cout << mFirstName << " has " << mMoney << " euros";

	if (mHasCar)
		std::cout << " and has " << mCar.GetBrand() << " " << mCar.GetModel() << " (" << mCar.GetPlate() << ")" << std::endl;
	else
		std::cout << " ans has no car" << std::endl;
}

void Person::BuyCar(Person seller, Car car)
{
	int price = 0;
	if (!seller.CheckHasCar())
	{
		cout << seller.GetName() << " has no car" << std::endl;
		return;
	}
	else if (car.GetPriceValue() > mMoney)
	{
		price = car.GetPriceValue();
		cout << "The price of the car is too high" << std::endl;
		return;
	}

	std::cout << mFirstName << " buys a car from " << seller.GetName() << std::endl;
	std::cout << "The car is a" << mCar.GetBrand() << " " << mCar.GetModel() << " (" << mCar.GetPlate() << ")";
	std::cout << " and costed " << price << " euros" << std::endl;

	mMoney -= price;
	mCar = car;
	mHasCar = true;

	seller.SellCar(price);

	cout << seller.GetName() << " has now " << seller.GetMoney() << " euros" << std::endl;
	cout << mFirstName << " has now " << mMoney << " euros" << std::endl;
}

void Person::SellCar(int price)
{
	mMoney += price;
	mHasCar = false;
}

void Person::DriveCar(int distanceInKm)
{
	mCar.Roll(distanceInKm);
}

void Person::PaintCar(Color color)
{
	mCar.ChangeColor(color);
}

void Person::BuyCarFromDealership(Car car)
{
	mMoney -= car.GetPriceValue();
	Car* ptr = &mCar;
	*ptr = car;

	mHasCar = true;
}