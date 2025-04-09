
// Yıldız Alara Köymen - 2453389
// I read and accept the submission rules and the extra rules specified in each question.
// This is my own work that is done by myself only.

#include "Company.h"
#include "Branch.h"
#include "Vehicle.h"
#include <cstring>
#include <iostream>

using namespace std;

Company::Company()
{
    Name = new char[20];
    strcpy(Name, "Undefined");
    number_of_branches = 0;
    int i;
    for(i = 0; i < 10; i++)
        branches[i] = nullptr;
}

Company::Company(char* Name)
{
    this->Name = new char[20];
    strcpy(this->Name, Name);
    this->number_of_branches = 0;
    int i;
    for(i = 0; i < 10; i++)
        branches[i] = nullptr;
}

char *Company::get_Name()
{
    return Name;
}

void Company::set_Name(char *Name)
{
    strcpy(this->Name, Name);
}

int Company::get_number_of_branches()
{
    return number_of_branches;
}

void Company::set_number_of_branches(int number_of_branches)
{
    this->number_of_branches = number_of_branches;
}

void Company::addBranch(Branch &branch)
{
    if (number_of_branches == 10)
        cout << "Branches are full..." << endl;
    else
    {
        this->branches[number_of_branches] = &branch;
        number_of_branches++;
    }

}

void Company::printBranches()
{
    int i;
    for (i = 0; i < number_of_branches; i++)
        branches[i]->printBranch();
}

void Company::printVehicles()
{
    int i;
    for(i = 0; i < number_of_branches; i++)
    {
        if(branches[i]->get_number_of_vehicles()!= 0)
        {
            cout << "Vehicles at Branch with ID " << branches[i]->get_Branch_ID() << ":" << endl;
            branches[i]->printVehicles();
        }
    }

}

void Company::printTypeStatistics()
{
    int i;
    int number_of_buses = 0;
    int number_of_cars = 0;
    for (i = 0; i < number_of_branches; i++)
        branches[i]->printTypeStatistics(number_of_cars, number_of_buses);

}

void Company::printVehiclesBySeat(int number_of_people)
{
    int i;
    for(i = 0; i < number_of_branches; i++)
        branches[i]->printVehiclesBySeat(number_of_people);

}

void Company::printVehiclesByType(int type)
{
    int i;
    for(i = 0; i < number_of_branches; i++)
        branches[i]->printVehiclesByType(type,branches[i]->get_Branch_ID());
}

void Company::printAnnualCost()
{
    int i;
    float sum = 0;
    for(i = 0; i < number_of_branches; i++)
        sum = branches[i]->printAnnualCost() + sum;

    cout << "---------------------" << endl;
    cout << "Total Annual Cost for Quick Transport is " << sum << endl;
}

int Company::doesBranchIDexist(int Branch_ID)
{
    int i;
    for(i = 0; i < number_of_branches; i++)
    {
        if(branches[i]->get_Branch_ID() == Branch_ID)
            return 1;
    }
    return 0;
}

int Company::get_Branch_Index(int Branch_ID)
{
    int i;
    for(i = 0; i < number_of_branches; i++)
    {
        if(Branch_ID == branches[i]->get_Branch_ID())
            return i;
    }
    return -1;
}

void Company::addVehicle(int Branch_ID, Vehicle &vehicle)
{
    branches[get_Branch_Index(Branch_ID)]->addVehicle(vehicle);
}

Company::Company(const Company & cmp)
{
    this->Name = new char[20];
    strcpy(Name, cmp.Name);
    int i;
    for(i = 0; i < number_of_branches; i++)
        this->branches[i] = nullptr;
    for(i = 0; i < cmp.number_of_branches; i++)
        this->branches[i] = cmp.branches[i];

    this->number_of_branches = cmp.number_of_branches;

}

Company::~Company()
{
    delete[] Name;
    int i;
    for(i = 0; i < number_of_branches; i++)
        delete branches[i];
}

Company &Company::operator=(const Company& cmp)
{
    if(this == &cmp)
        return *this;

    delete[] Name;
    Name = new char[20];
    strcpy(Name, cmp.Name);

    int i;
    for(i = 0; i < number_of_branches; i++)
        branches[i] = nullptr;

    for (i = 0; i < cmp.number_of_branches; i++)
        branches[i] = cmp.branches[i];

    number_of_branches = cmp.number_of_branches;

    return *this;
}

int Company::check_vehicle_ID(int Branch_ID, int Vehicle_ID)
{
    int i;
    int index = get_Branch_Index(Branch_ID);
    for(i = 0; i < branches[index]->get_number_of_vehicles(); i++)
    {
        
        if(branches[index]->check_vehicle_ID(i) == Vehicle_ID)
            return 0;
    }
    return 1;
}


