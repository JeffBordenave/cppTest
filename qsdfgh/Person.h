#pragma once
#include <iostream>
#include <string>

#include "Car.h"
#include "Color.h"
#include "Gender.h"

class Person
{
	/*1. Create the Person class :
		A person has : A first name, a last name, a birth date, money, a carand a gender
		A person can : Introduce themselves, Buy a car, Sell a car, Roll in the car, Paint the car
	*/
private :
	std::string mFirstName;
	std::string mLastName;
	Gender mGender;
	int mDayOfBirth;
	int mMonthOfBirth;
	int mYearOfBirth;
	float mMoney;
	bool mHasCar;
	Car mCar;
public :
	Person();
	Person(std::string firstName, std::string lastName);
	Person(std::string firstName, std::string lastName, Gender gender);
	Person(std::string firstName, std::string lastName, Gender gender, int dayOfBirth, int monthOfBirth, int yearOfBirth);
	Person(std::string firstName, std::string lastName, Gender gender, int dayOfBirth, int monthOfBirth, int yearOfBirth, float money);
	Person(std::string firstName, std::string lastName, Gender gender, int dayOfBirth, int monthOfBirth, int yearOfBirth, float money, Car car);
	~Person();

	string GetName();
	bool CheckHasCar();
	Car GetCar();
	int GetMoney();

	void IntroduceSelf();
	void BuyCar(Person seller, Car car, float price);
	void SellCar(float price);
	void DriveCar(float distanceInKm);
	void PaintCar(Color color);
};