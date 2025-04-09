
// Yıldız Alara Köymen - 2453389
// I read and accept the submission rules and the extra rules specified in each question.
// This is my own work that is done by myself only.

#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"



class Car: public Vehicle
{
public:
    enum carType{None, Sedan, Hatchback, Limousine};
    carType cartype;
    Car();
    Car(int, char*, char*, char*, carType cartype);
    int getSeats();
    int checkSuitability(int) override;
    float annualCost() override;
    void printVehicle() override;
    void printVehiclesByType(int, int) override;
    void countVehiclesByType(int &number_of_cars, int &number_of_buses) override;
};

#endif //CAR_H
