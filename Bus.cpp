
// Yıldız Alara Köymen - 2453389
// I read and accept the submission rules and the extra rules specified in each question.
// This is my own work that is done by myself only.

#include "Bus.h"
#include <cstring>
#include <iostream>
using namespace std;

Bus::Bus()
{
    Vehicle_ID = -1;
    strcpy(Brand, "Undefined");
    strcpy(Model, "Undefined");
    strcpy(Plate_number, "Undefined");
    number_of_seats = 0;
}

Bus::Bus(int Vehicle_ID, char *Brand, char *Model, char *Plate_number, int number_of_seats) : Vehicle(Vehicle_ID, Brand, Model, Plate_number)
{
    this->number_of_seats = number_of_seats;
}

int Bus::checkSuitability(int number_of_people)
{
    if(number_of_seats>= number_of_people)
        return 1;
    else
        return 0;
}

float Bus::annualCost() {
    float maintenance_cost;
    float number_of_time_serviced;
    cout << "Enter the maintenance cost: ";
    cin >> maintenance_cost;
    cout << "Enter the number of times bus has been serviced: ";
    cin >> number_of_time_serviced;
    return maintenance_cost * number_of_time_serviced;
}

void Bus::printVehicle() {

    cout << "Vehicle ID: " << Vehicle_ID << ", Brand: " << Brand << ", Model: " << Model << ", Plate Number: " << Plate_number;
    cout << ", Car Type: Bus, Number of Seats: " << number_of_seats << endl;
}

void Bus::printVehiclesByType(int choice, int Branch_ID)
{
    if(choice == 0)
    {
        cout << "Vehicle at Branch with ID: " << Branch_ID << endl;
        cout << "Vehicle ID: " << Vehicle_ID << ", Brand: " << Brand << ", Model: " << Model << ", Plate Number: " << Plate_number;
        cout << ", Car Type: Bus, Number of Seats: " << number_of_seats << endl;
    }
}

void Bus::countVehiclesByType(int &number_of_cars, int &number_of_buses)
{
    number_of_buses++;
}

