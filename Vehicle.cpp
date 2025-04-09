
// Yıldız Alara Köymen - 2453389
// I read and accept the submission rules and the extra rules specified in each question.
// This is my own work that is done by myself only.

#include "Vehicle.h"
#include <cstring>
using namespace std;

Vehicle::Vehicle()
{
    Vehicle_ID = -1;
    strcpy(Brand, "Undefined");
    strcpy(Model, "Undefined");
    strcpy(Plate_number, "Undefined");

}
Vehicle::Vehicle(int Vehicle_ID, char* Brand, char* Model, char* Plate_number)
{
    this->Vehicle_ID = Vehicle_ID;
    strcpy(this->Brand, Brand);
    strcpy(this->Model, Model);
    strcpy(this->Plate_number, Plate_number);
}

int Vehicle::get_Vehicle_ID()
{
    return this->Vehicle_ID;
}

void Vehicle::set_Vehicle_ID(int Vehicle_ID)
{
    this->Vehicle_ID = Vehicle_ID;
}

char *Vehicle::get_Brand()
{
    return Brand;
}

void Vehicle::set_Brand(char* Brand)
{
    strcpy(this->Brand, Brand);
}

char *Vehicle::get_Model()
{
    return Model;
}

void Vehicle::set_Model(char* Model)
{
    strcpy(this->Model, Model);
}

char *Vehicle::get_Plate_number()
{
    return Plate_number;
}

void Vehicle::set_Plate_number(char* Plate_number)
{
    strcpy(this->Plate_number,Plate_number);
}

void Vehicle::printVehicle() {}

int Vehicle::checkSuitability(int){return 0;}

float Vehicle::annualCost()
{
    return 0;
}

void Vehicle::printVehiclesByType(int type, int Branch_ID){}

void Vehicle::countVehiclesByType(int &number_of_cars, int &number_of_buses){}

