# A-Transportation-Company-Management-System
A storage system for a transportation company

README  
------------------------------------------------------------
Transportation Company Management System  
Company Name: Quick Transport  
Language: C++  
------------------------------------------------------------

C++ Classes

1. Company
   - Attributes:
     - Name (char pointer)
     - Branches (array of Branch objects, max size = 10)
     - Number of branches (int)
   - Key Functions:
     - Default and parameterized constructors
     - Getters and setters
     - addBranch()
     - printBranches()
     - printVehicles()
     - printVehiclesByType(type)
     - printTypeStatistics()
     - printVehiclesBySeat(seatCount)
     - printAnnualCost()

2. Branch
   - Attributes:
     - Branch ID (int)
     - City (char pointer)
     - Vehicles (array of Vehicle pointers, max size = 30)
     - Number of vehicles (int)
   - Key Functions:
     - Default and parameterized constructors
     - Getters and setters
     - addVehicle()
     - printBranch()
     - printVehicles()
     - printVehiclesByType(type)
     - printTypeStatistics()
     - printVehiclesBySeat(seatCount)
     - printAnnualCost()

3. Vehicle (Base Class)
   - Attributes:
     - Vehicle ID (int)
     - Brand (char pointer)
     - Model (char pointer)
     - Plate No (char pointer)
   - Key Functions:
     - Default and parameterized constructors
     - Getters and setters
     - printVehicle()

4. Car (Inherits Vehicle)
   - Additional Attribute:
     - Car Type (enum: None, Sedan, Hatchback, Limousine)
   - Key Functions:
     - getSeats()
     - checkSuitability(people)
     - annualCost() [10$ per km]
     - printVehicle()

5. Bus (Inherits Vehicle)
   - Additional Attribute:
     - Number of seats (int)
   - Key Functions:
     - checkSuitability(people)
     - annualCost() [maintenanceCost × serviceCount]
     - printVehicle()

------------------------------------------------------------
Management System Interface

The program should provide the following interactive menu for “Quick Transport”:

1. Add a new branch to the company.
2. Add a new vehicle (car or bus) to a branch.
3. Print all branches with cities and vehicle counts.
4. Print details of all vehicles in each branch.
5. Print vehicles of a given type in each branch.
6. Print type statistics (number of cars and buses) in each branch.
7. Print vehicles that can carry a given number of people in each branch.
8. Calculate and print the total annual cost for the company.
9. Exit.

------------------------------------------------------------
Development Requirements:
- Follow object-oriented principles.
- Use appropriate access specifiers.
- Implement copy constructors, destructors, and assignment operators for any class with heap memory.
- Separate class definitions and implementations across `.h` and `.cpp` files.

------------------------------------------------------------
Additional Notes:
- Use dynamic memory allocation where required.
- Avoid memory leaks; manage heap memory carefully.
- Ensure modular and reusable code structure.
- Use meaningful naming conventions and add comments for clarity.

------------------------------------------------------------
