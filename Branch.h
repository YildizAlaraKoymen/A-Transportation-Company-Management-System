
// Yıldız Alara Köymen - 2453389
// I read and accept the submission rules and the extra rules specified in each question.
// This is my own work that is done by myself only

#ifndef BRANCH_H
#define BRANCH_H
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
class Branch
{
protected:
    int Branch_ID;
    char* City;
    int number_of_vehicles;
    Vehicle *vehicles[30];
public:
    Branch();
    Branch(int, char*);
    Branch(const Branch &br);
    Branch& operator=(const Branch &br);
    ~Branch();
    int get_Branch_ID();
    void set_Branch_ID(int);
    char* get_City();
    void set_City(char*);
    int get_number_of_vehicles();
    void set_number_of_vehicles(int);
    void addVehicle(Vehicle &vehicle);
    void printBranch();
    int check_vehicle_ID(int);

    void printVehicles();
    void printVehiclesByType(int, int);

    void printTypeStatistics(int, int);
    void printVehiclesBySeat(int);

    float printAnnualCost();

};

#endif //BRANCH_H
