
// Yıldız Alara Köymen - 2453389
// I read and accept the submission rules and the extra rules specified in each question.
// This is my own work that is done by myself only.

#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

class Bus: public Vehicle
{
private:
    int number_of_seats;
public:
    Bus();
    Bus(int, char*, char*, char*, int);
    int checkSuitability(int) override;
    float annualCost() override;
    void printVehicle() override;
    void printVehiclesByType(int, int) override;
    void countVehiclesByType(int &number_of_cars, int &number_of_buses) override;
};

#endif //BUS_H
