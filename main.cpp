
// Yıldız Alara Köymen - 2453389
// I read and accept the submission rules and the extra rules specified in each question.
// This is my own work that is done by myself only.

#include <iostream>
#include "Company.h"
#include "Branch.h"
#include "Car.h"
#include "Bus.h"
#include <cstring>

using namespace std;

int main() {
    int selection = 0;

    Company myCompany("Quick Transport");
    cout << "Welcome to " << myCompany.get_Name() << endl;

    while(selection != 9)
    {

        cout << "\nOptions:" << endl;
        cout << "1. Add a new branch to the company." << endl;
        cout << "2. Add a new vehicle (car or bus) to a branch." << endl;
        cout << "3. Print all the branches along with their cities and the number of vehicles." << endl;
        cout << "4. Print the details stored as member variables for the vehicles in each branch." << endl;
        cout << "5. Print the details stored as member variables for the vehicles in each branch whose type is a given type." << endl;
        cout << "6. Print the number of each type of vehicle in each branch." << endl;
        cout << "7. Print the details stored as member variables for the vehicles that can carry a given number of people in each branch." << endl;
        cout << "8. Calculate the total annual cost for the company." << endl;
        cout << "9. Exit" << endl;

        cout << "Your selection: ";
        cin >> selection;

        switch (selection)
        {
            case(1):
            {
                int Branch_ID;
                char City[20];

                cout << "Please enter branch's ID: ";
                cin >> Branch_ID;
                if(myCompany.doesBranchIDexist(Branch_ID) == 1)
                {
                    cout << "Branch already exists." << endl;
                    break;
                }
                cout << "Please enter the city, where branch is located: ";
                cin >> City;

                Branch *branch;
                branch = new Branch(Branch_ID, City);
                myCompany.addBranch(*branch);
                break;
            }
            case(2):
            {
                int Branch_ID, choice, Vehicle_ID;
                char Brand[20], Model[20], Plate_number[20];
                string line;
                cout << "Please enter the ID of the Branch: ";
                cin >> Branch_ID;
                if(myCompany.doesBranchIDexist(Branch_ID) == 0)
                {
                    cout << "There is no branch with ID " << Branch_ID << " at " << myCompany.get_Name() << endl;
                    break;
                }
                cout << "What type of vehicle would you like to add?" << endl;
                cout << "Possible options: (0) Bus, (1) Sedan, (2) Hatchback, (3) limousine" << endl;
                cout << "Your choice: ";
                cin >> choice;
                if(choice != 0 && choice != 1 && choice != 2 && choice != 3)
                {
                    cout << "Please enter a proper input " << endl;
                    break;
                }
                cout << "Please enter the ID of the vehicle: ";
                cin >> Vehicle_ID;
                if(myCompany.check_vehicle_ID(Branch_ID, Vehicle_ID) == 0)
                {
                    cout << "Vehicle already exists." << endl;
                    break;
                }
                cout << "Please enter the brand of the vehicle: ";
                getline(cin, line);
                strcpy(Brand, line.c_str());
                cin.getline(Brand, 100);
                cout << "Please enter the model of the vehicle: ";
                getline(cin, line);
                strcpy(Model, line.c_str());
                cout << "Please enter the plate number of the vehicle: ";
                getline(cin, line);
                strcpy(Plate_number, line.c_str());

                Bus *bus;
                Car *car;
                if(choice == 0)
                {
                    int number_of_seats;
                    cout << "Please enter the number of seats on the Bus: ";
                    cin >> number_of_seats;
                    bus = new Bus(Vehicle_ID, Brand, Model, Plate_number, number_of_seats);
                    myCompany.addVehicle(Branch_ID, *bus);
                }
                else if(choice == 1)
                {
                    car = new Car(Vehicle_ID, Brand, Model, Plate_number, Car::carType::Sedan);
                    myCompany.addVehicle(Branch_ID, *car);
                }
                else if(choice == 2)
                {
                    car = new Car(Vehicle_ID, Brand, Model, Plate_number, Car::carType::Hatchback);
                    myCompany.addVehicle(Branch_ID, *car);
                }
                else if(choice == 3)
                {
                    car = new Car(Vehicle_ID, Brand, Model, Plate_number, Car::carType::Limousine);
                    myCompany.addVehicle(Branch_ID, *car);
                }
                break;
            }
            case(3):
            {
                myCompany.printBranches();
                break;
            }
            case(4):
            {
                myCompany.printVehicles();
                break;
            }
            case(5):
            {
                int choice;
                cout << "Please select the type of the vehicles, You want to see: (0) Bus, (1) Car" << endl;
                cout << "Your choice: ";
                cin >> choice;
                if(choice != 0 && choice != 1)
                {
                    cout << "Please enter a proper input " << endl;
                    break;
                }
                myCompany.printVehiclesByType(choice);
                break;
            }
            case(6):
            {
                myCompany.printTypeStatistics();
                break;
            }
            case(7):
            {
                int number_of_passengers;
                cout << "Please enter the number of passengers vehicle should be able to carry: ";
                cin >> number_of_passengers;
                myCompany.printVehiclesBySeat(number_of_passengers);
                break;
            }
            case(8):
            {
                myCompany.printAnnualCost();
                break;
            }
            case(9):
            {
                cout << "Good Bye! " << endl;
                exit(true);
            }
            default:
            {
                cout << "Wrong input!, Please enter again!";
                break;
            }

        }

    }

    return 0;
}
