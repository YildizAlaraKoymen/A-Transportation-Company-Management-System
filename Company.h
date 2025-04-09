
// Yıldız Alara Köymen - 2453389
// I read and accept the submission rules and the extra rules specified in each question.
// This is my own work that is done by myself only.

#ifndef COMPANY_H
#define COMPANY_H
#include "Branch.h"

class Company
{
private:
    char *Name;
    Branch *branches[10];
    int number_of_branches;
public:
    Company();
    Company(char*);
    Company(const Company &cmp);
    Company& operator=(const Company &cmp);
    ~Company();
    char* get_Name();
    void set_Name(char*);
    int get_number_of_branches();
    void set_number_of_branches(int);
    int check_vehicle_ID(int, int);
    void addBranch(Branch &branch);
    int get_Branch_Index(int);
    virtual void addVehicle(int, Vehicle &vehicle);
    void printBranches();
    void printVehicles();
    void printVehiclesByType(int);
    void printTypeStatistics();
    void printVehiclesBySeat(int);
    void printAnnualCost();
    int doesBranchIDexist(int);

};
#endif //COMPANY_H
