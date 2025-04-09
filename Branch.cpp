
// Yıldız Alara Köymen - 2453389
// I read and accept the submission rules and the extra rules specified in each question.
// This is my own work that is done by myself only


#include "Branch.h"
#include "Vehicle.h"
#include <iostream>
#include <cstring>
using namespace std;

Branch::Branch()
{
    Branch_ID = -1;
    City = new char[20];
    strcpy(City, "Undefined");
    number_of_vehicles = 0;
    int i;
    for(i = 0; i < 30; i++)
        vehicles[i] = nullptr;
}

Branch::Branch(int Branch_ID, char* City)
{
    this->City = new char[20];
    this->Branch_ID = Branch_ID;
    strcpy(this->City, City);
    this->number_of_vehicles = 0;
    int i;
    for(i = 0; i < 30; i++)
        vehicles[i] = nullptr;
}

int Branch::get_Branch_ID()
{
    return Branch_ID;
}

void Branch::set_Branch_ID(int Branch_ID)
{
    this->Branch_ID = Branch_ID;
}

char *Branch::get_City()
{
    return City;
}

void Branch::set_City(char *City)
{
    strcpy(this->City, City);
}

int Branch::get_number_of_vehicles()
{
    return number_of_vehicles;
}

void Branch::set_number_of_vehicles(int number_of_vehicles)
{
    this->number_of_vehicles =number_of_vehicles;
}

void Branch::addVehicle(Vehicle &vehicle)
{
    if (number_of_vehicles == 30)
        cout << "Vehicles are full..." << endl;
    else
    {
        this->vehicles[number_of_vehicles] = &vehicle;

        number_of_vehicles++;
        cout << "Vehicle is successfully added!" << endl;
    }

}


void Branch::printBranch()
{
    cout << "City: " << City;
    cout <<", Number of vehicles: " << number_of_vehicles << endl;
}

void Branch::printVehicles()
{
    int i;
    for (i = 0; i < number_of_vehicles; i++)
        vehicles[i]->printVehicle();

}


void Branch::printVehiclesByType(int type, int Branch_ID)
{
    int i;

    for(i = 0; i < number_of_vehicles; i++)
        vehicles[i]->printVehiclesByType(type, Branch_ID);

}

void Branch::printTypeStatistics(int number_of_cars, int number_of_buses)
{
    cout << "At Branch with ID: " << Branch_ID << " there are: " <<endl;
    int i;
    for(i = 0; i < number_of_vehicles; i++)
    {
        vehicles[i]->countVehiclesByType(number_of_cars, number_of_buses);
    }
    cout << "   " << number_of_buses << " buse(es)" << endl;
    cout << "   " << number_of_cars << " car(s)" << endl;
}

void Branch::printVehiclesBySeat(int number_of_people)
{
    int i;
    for (i = 0; i < number_of_vehicles; i++)
    {
        if (vehicles[i]->checkSuitability(number_of_people) == 1)
        {
            cout << "Vehicle at Branch with ID: " << Branch_ID << endl;
            vehicles[i]->printVehicle();
        }

    }

}

float Branch::printAnnualCost() {
    cout << "Vehicles at Branch with ID " << Branch_ID <<":" << endl;
    int i;
    float sum = 0;
    for (i = 0; i < number_of_vehicles; i++)
    {
        cout << "Vehicle " << i + 1 << ":" << endl;
        sum = vehicles[i]->annualCost() + sum;
    }

    cout << "Total Annual Cost for Branch with ID: " << Branch_ID << " is " << sum << endl;
    return sum;
}

Branch::Branch(const Branch &br)
{
    Branch_ID = br.Branch_ID;
    City = new char[20];
    strcpy(City, br.City);
    int i;
    for(i = 0; i < number_of_vehicles; i++)
        vehicles[i] = nullptr;
    for(i = 0; i < br.number_of_vehicles; i++)
        vehicles[i] = br.vehicles[i];

    number_of_vehicles = br.number_of_vehicles;

}

Branch &Branch::operator=(const Branch &br) {
    if (this == &br)
        return *this;

    delete[] City;

    Branch_ID = br.Branch_ID;
    City = new char[20];
    strcpy(City, br.City);
    int i;
    for(i = 0; i < number_of_vehicles; i++)
        vehicles[i] = nullptr;
    for(i = 0; i < br.number_of_vehicles; i++)
        vehicles[i] = br.vehicles[i];

    number_of_vehicles = br.number_of_vehicles;

    return *this;
}

Branch::~Branch()
{
    delete[] City;
    int i;
    for(i = 0; i < number_of_vehicles; i++)
        delete vehicles[i];
}

int Branch::check_vehicle_ID(int i)
{
    return this->vehicles[i]->get_Vehicle_ID();
}








