# Assignment: Employee Management System

You are tasked with developing an Employee Management System in C. The system should allow users to store and manipulate employee records. Follow the instructions below to complete the assignment:

1. Define a class called "Employee" with the following attributes:
    - id (integer)
    - name (string)
    - salary (float)
  
2. Implement the following member functions in the Employee class:
    - A default constructor to initialize the attributes.
    - A parameterized constructor to set the attributes based on user input.
    - Overload the input and output operators (>> and <<) to read and display employee records.

3. Create a derived class called "Manager" that inherits from the Employee class. Add an additional attribute to represent the department the manager oversees.

4. Implement the following member functions in the Manager class:
    - A default constructor that calls the base class constructor and initializes the department attribute.
    - Overload the input and output operators (>> and <<) to read and display manager records.

5. Create a menu-driven program that allows users to perform the    following operations:
    - Add a new employee or manager record to a file.
    - Display all employee or manager records from the file.
    - Search for an employee or manager by ID and display their record.
    - Modify the salary of an employee or manager by ID.
    - Exit the program.

6. Implement file handling techniques to store and retrieve employee and manager records in a binary file. Use random access techniques to modify the records.

## Submission Guidelines

- Write a well-commented C program that includes the Employee and Manager classes, along with the menu-driven program.
- Ensure that the program handles errors gracefully and provides appropriate feedback to the user.
- Submit your program file along with a brief report explaining your approach and any challenges faced during the implementation.

Note: This assignment is intended to assess your understanding of the concepts of function overloading, operator overloading, inheritance, and random access in C. Ensure that you demonstrate your knowledge of these topics in your solution.

