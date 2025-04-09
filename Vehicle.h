
// Yıldız Alara Köymen - 2453389
// I read and accept the submission rules and the extra rules specified in each question.
// This is my own work that is done by myself only.

#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
protected:
    int Vehicle_ID;
    char Brand[20];
    char Model[20];
    char Plate_number[20];
public:
    Vehicle();
    Vehicle(int, char*, char*, char*);
    int get_Vehicle_ID();
    void set_Vehicle_ID(int);
    char* get_Brand();
    void set_Brand(char*);
    char* get_Model();
    void set_Model(char*);
    char* get_Plate_number();
    void set_Plate_number(char*);
    virtual void printVehicle();
    virtual int checkSuitability(int);
    virtual float annualCost();
    virtual void printVehiclesByType(int, int);
    virtual void countVehiclesByType(int &number_of_cars, int &number_of_buses);

};

#endif //VEHICLE_H
