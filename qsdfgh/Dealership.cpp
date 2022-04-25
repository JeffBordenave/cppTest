#include "Dealership.h"
#include <string>
#include "Gender.h"
#include "Color.h"

Dealership::Dealership() 
{
	mMoney = 0;
	mCarsOwned = {};
	mCustomers = {};
}

Dealership::~Dealership(){}

vector<Person> Dealership::GetCustomers() { return mCustomers; }

void Dealership::CreatePerson() 
{
	string firstName;
	string lastName;
	Gender gender;
	int day;
	int month;
	int year;
	int money;

	int genderInt;

	cout << "Create a new person" << endl;
	cout << "Type first name :" << endl;
	cin >> firstName;

	cout << "Type last name :" << endl;
	cin >> lastName;

	cout << "Choose gender :" << endl;
	cout << "1. Man" << endl;
	cout << "2. Woman" << endl;
	cout << "3. Non-Binary" << endl;
	cin >> genderInt;

	switch (genderInt) 
	{
	case 1:
		gender = Gender::Man;
		break;

	case 2:
		gender = Gender::Woman;
		break;

	case 3:
		gender = Gender::NonBinary;
		break;

	default:
		gender = Gender::DefGender;
		break;
	}

	cout << "Type birth date" << endl;
	cout << "Day :" << endl;
	cin >> day;

	cout << "Month :" << endl;
	cin >> month;

	cout << "Year :" << endl;
	cin >> year;

	cout << "Type money :" << endl;
	cin >> money;

	Person person = Person(firstName, lastName, gender, day, month, year, money);

	mCustomers.push_back(person);
}

void Dealership::CreateCar()
{
	string brand;
	string model;
	Color color;
	string licencePlate;
	int year;
	int mileage;
	int costValue;

	int colorInt;

	cout << "Create a new car" << endl;
	cout << "Type brand :" << endl;
	cin >> brand;

	cout << "Type model :" << endl;
	cin >> model;

	cout << "Choose color :" << endl;
	cout << "1. Red" << endl;
	cout << "2. Green" << endl;
	cout << "3. Blue" << endl;
	cout << "4. Yellow" << endl;
	cout << "5. Cyan" << endl;
	cout << "6. Magenta" << endl;

	cin >> colorInt;

	switch (colorInt)
	{
	case 1:
		color = Color::Red;
		break;

	case 2:
		color = Color::Green;
		break;

	case 3:
		color = Color::Blue;
		break;

	case 4:
		color = Color::Yellow;
		break;

	case 5:
		color = Color::Cyan;
		break;

	case 6:
		color = Color::Magenta;
		break;

	default:
		Color = Color::DefColor;
		break;
	}

	cout << "Type license plate" << endl;
	cin >> licencePlate;

	cout << "Type mileage :" << endl;
	cin >> mileage;

	cout << "Type year of construction :" << endl;
	cin >> year;

	cout << "Type cost value :" << endl;
	cin >> costValue;

	Car car = Car(brand,model,color,licencePlate,year,mileage,costValue);

	mCarsOwned.push_back(car);
}