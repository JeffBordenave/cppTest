#include "Dealership.h"
#include <string>
#include "Gender.h"
#include "Color.h"

Dealership::Dealership() 
{
	mMoney = 3000;
	mCarsOwned = {};
	mCustomers = {};
}

Dealership::~Dealership(){}

vector<Person> Dealership::GetCustomers() { return mCustomers; }
vector<Car> Dealership::GetCarsOwned() { return mCarsOwned; }
int Dealership::GetMoney() { return mMoney; }

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
		color = Color::DefColor;
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

void Dealership::SellCarToCustomer(Person customer)
{
	int carChosen = 0;

	if (mCarsOwned.size() == 0) 
	{
		cout << "You don't have any car" << endl;
		return;
	}

	cout << "You have " << mCarsOwned.size() << " cars" << endl;
	cout << "These are your cars :" << endl;

	for (size_t i = 0; i < mCarsOwned.size(); i++)
	{
		cout << i + 1 << ". " << mCarsOwned[i].GetBrand() << " " << mCarsOwned[i].GetModel() << endl;
	}

	cout << "Choose the car to sell :" << endl;
	cin >> carChosen;

	while (carChosen <= 0 || unsigned(carChosen) > mCarsOwned.size())
	{
		cout << "invalid answer" << endl;
		cout << "Choose the car to sell :" << endl;
		cin >> carChosen;
	}
	
	carChosen--;

	if (mCarsOwned[carChosen].GetPriceValue() > customer.GetMoney()) 
	{
		cout << "The customer doesn't have enough money to buy the car" << endl;
		return;
	}
	else
	{
		customer.BuyCarFromDealership(mCarsOwned[carChosen]);
	}

	mMoney += mCarsOwned[carChosen].GetPriceValue();

	cout << customer.GetName() << "'s car is now a "; 
	cout << customer.GetCar().GetBrand() << " " << customer.GetCar().GetModel() << endl;
	cout << customer.GetName() << " now has " << customer.GetMoney() << " euros" << endl;

	mCarsOwned.erase(mCarsOwned.begin() + carChosen);
}

void Dealership::BuyCarFromCustomer(Person customer)
{
	if (!customer.CheckHasCar())
	{
		cout << "The customer doesn't have a car" << endl;
		return;
	}
	else if (customer.GetCar().GetPriceValue() > mMoney)
	{
		cout << "You don't have enough money to buy the customer's car" << endl;
		return;
	}

	cout << "You bought a " << customer.GetCar().GetBrand() << " " << customer.GetCar().GetModel();
	cout << " from " << customer.GetName() << endl;

	mMoney -= customer.GetCar().GetPriceValue();
	customer.SellCar(customer.GetCar().GetPriceValue());
	mCarsOwned.push_back(customer.GetCar());

	cout << "You now have " << mMoney << " euros" << endl;
	cout << customer.GetName() << " now has " << customer.GetMoney() << endl;
}

void Dealership::Menu() 
{
	cout << "You have " << mMoney << " euros" << endl;
	int actionChosen = 0;
	cout << "Choose an action :" << endl;
	cout << "1. Create a customer" << endl;
	cout << "2. Create a car" << endl;
	cout << "3. View customers" << endl;
	cout << "4. View cars" << endl;
	cout << "5. Sell a car to a customer" << endl;
	cout << "6. Buy a car from a customer" << endl;
	cout << "Type any other number to exit" << endl;

	cin >> actionChosen;

	switch (actionChosen)
	{
	case 1:
		CreatePerson();
		Menu();
		break;
	case 2:
		CreateCar();
		Menu();
		break;
	case 3:
		for (size_t i = 0; i < mCustomers.size(); i++)
		{
			cout << i + 1 << ". " << mCustomers[i].GetName() << " has " << mCustomers[i].GetMoney() << " euros" << endl;
			if (mCustomers[i].CheckHasCar())
				cout << " and has a " << mCustomers[i].GetCar().GetBrand() << endl;
		}
		Menu();
		break;
	case 4:
		for (size_t i = 0; i < mCarsOwned.size(); i++)
		{
			cout << i + 1 << ". " << mCarsOwned[i].GetBrand() << " " << mCarsOwned[i].GetModel() << " (" << mCarsOwned[i].GetPlate() << ")";
			cout << " costs " << mCarsOwned[i].GetPriceValue() << endl;
		}
		Menu();
		break;
	case 5:
		cout << "Choose customer to sell a car to :" << endl;

		int customer;
		do
		{
			for (size_t i = 0; i < mCustomers.size(); i++)
			{
				cout << i + 1 << ". " << mCustomers[i].GetName() << " has " << mCustomers[i].GetMoney() << " euros" << endl;
				if (mCustomers[i].CheckHasCar())
					cout << " and has a " << mCustomers[i].GetCar().GetBrand() << endl;
			}
			cin >> customer;
		} while (customer <= 0 || (unsigned)customer > mCustomers.size());

		SellCarToCustomer(mCustomers[customer-1]);
		Menu();
		break;
	case 6:
		cout << "Choose customer to buy a car from :" << endl;

		int customerChoice;
		do
		{
			for (size_t i = 0; i < mCustomers.size(); i++)
			{
				cout << i + 1 << ". " << mCustomers[i].GetName() << " has " << mCustomers[i].GetMoney() << " euros" << endl;
				if (mCustomers[i].CheckHasCar())
					cout << " and has a " << mCustomers[i].GetCar().GetBrand() << endl;
			}
			cin >> customerChoice;
		} while (customerChoice < 0 || (unsigned)customerChoice > mCustomers.size());

		BuyCarFromCustomer(mCustomers[customerChoice-1]);
		Menu();
		break;

	default:
		break;
	}
}