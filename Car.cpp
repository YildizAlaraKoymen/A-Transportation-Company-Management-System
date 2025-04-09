
// Yıldız Alara Köymen - 2453389
// I read and accept the submission rules and the extra rules specified in each question.
// This is my own work that is done by myself only.

#include "Car.h"
#include "Vehicle.h"
#include <cstring>
#include <iostream>
using namespace std;

Car::Car()
{
    Vehicle_ID = -1;
    strcpy(Brand, "Undefined");
    strcpy(Model, "Undefined");
    strcpy(Plate_number, "Undefined");
    cartype = carType::None;
}

Car::Car(int Vehicle_ID, char *Brand, char *Model, char *Plate_number, carType cartype) : Vehicle(Vehicle_ID, Brand, Model, Plate_number)
{
    this->cartype = cartype;
}

int Car::getSeats()
{
    if(cartype == carType::None)
        return 0;
    else if((cartype == carType::Sedan )||(cartype == carType::Hatchback))
        return 5;
    else if(cartype == carType::Limousine)
        return 6;
    else
        return -1;
}

int Car::checkSuitability(int number_of_people)
{
    if(getSeats() >= number_of_people)
        return 1;
    else
        return 0;
}

float Car::annualCost()
{
    float kilometers;
    cout << "Enter the kilometers driven: ";
    cin >> kilometers;
    return kilometers*float(10);
}

void Car::printVehicle()
{
    cout << "Vehicle ID: " << Vehicle_ID << ", Brand: " << Brand << ", Model: " << Model << ", Plate Number: " << Plate_number;
    cout << ", Car Type: ";
    if(cartype == carType::Limousine)
        cout << "Limousine" << endl;
    else if(cartype == carType::Hatchback)
        cout << "Hatchback" << endl;
    else if(cartype == carType::Sedan)
        cout << "Sedan" << endl;
}

void Car::printVehiclesByType(int choice, int Branch_ID)
{
    if(choice == 1)
    {
        cout << "Vehicle at Branch with ID: " << Branch_ID << endl;
        cout << "Vehicle ID: " << Vehicle_ID << ", Brand: " << Brand << ", Model: " << Model << ", Plate Number: " << Plate_number;
        cout << ", Car Type: ";
        if(cartype == carType::Limousine)
            cout << "Limousine" << endl;
        else if(cartype == carType::Hatchback)
            cout << "Hatchback" << endl;
        else if(cartype == carType::Sedan)
            cout << "Sedan" << endl;
    }

}

void Car::countVehiclesByType(int &number_of_cars, int &number_of_buses)
{
    number_of_cars++;
}
