#include <iostream>
#include <list>
#include <iterator>
#include "Car.h"
#include "Gender.h"
#include "Person.h"
#include "Color.h"
#include "Dealership.h"

int main()
{
    std::cout << "Hello World!\n";
    Car peugeot = Car("Peugeot", "3000", Color::Blue, "ceci est la plate", 2000, 30, 3000);
    Person jack = Person("Jack", "Sparrow", Gender::Man, 21, 5, 2001,5000, peugeot);
    Person jeanne = Person("Jeanne", "Oui", Gender::Woman, 31, 7, 2003 ,700);

    jeanne.BuyCar(jack, peugeot);

    Dealership dealership = Dealership();

    dealership.CreatePerson();
}