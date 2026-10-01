# University Management System in C++

A console-based C++ project designed to practice and demonstrate core object-oriented programming concepts, especially **inheritance and runtime polymorphism**.

## Project Overview

The system models different people in a university environment using a common base class and several derived classes.

The main goal of the project is to use a base-class pointer to work with different derived objects while allowing C++ to automatically select the correct overridden function at runtime.

The system will include several university roles such as:

- Student
- Graduate Student
- Professor
- Staff Member

Each role inherits common information from a base `Person` class while also having its own data and behavior.

## Concepts Practiced

This project is intended to practice:

- Classes and objects
- Encapsulation
- Private and public members
- Constructors
- Getters and setters
- Inheritance
- Base and derived classes
- Multilevel inheritance
- Virtual functions
- Function overriding
- `override`
- Base-class pointers
- The `->` operator
- Runtime polymorphism
- Constructor chaining
- Arrays or collections of base-class pointers

## Planned Class Structure

```text
                Person
              /   |    \
             /    |     \
        Student Professor Staff
           |
           |
    GraduateStudent
```

### Person

The base class will contain common information such as:

- Name
- ID
- Age

It will also define virtual functions that derived classes can override.

### Student

A derived class representing university students.

Additional information may include:

- Major
- GPA
- Completed credits

### GraduateStudent

A specialized type of `Student`.

Additional information may include:

- Research topic
- Supervisor
- Monthly stipend

### Professor

A derived class representing faculty members.

Additional information may include:

- Department
- Salary
- Courses taught

### Staff

A derived class representing university staff members.

Additional information may include:

- Department
- Position
- Salary

## Polymorphism

One of the main objectives of this project is to use polymorphism through base-class pointers.

For example, the program will be able to store different university members using `Person*` pointers and call functions such as:

```cpp
personPtr->displayInfo();
personPtr->performRole();
```

The function that actually executes will depend on the type of object that the pointer currently refers to.

This allows different types of university members to be handled through the same interface.

## Planned Features

The final system is planned to support:

1. Adding students
2. Adding graduate students
3. Adding professors
4. Adding staff members
5. Displaying information about all university members
6. Performing role-specific actions
7. Displaying salary or stipend information
8. Demonstrating runtime polymorphism
9. Managing different object types through base-class pointers

## Project Status

🚧 **In Progress**

This project is being developed while learning C++ object-oriented programming and will be updated as new concepts are implemented.

## Language

- C++

## Purpose

This project was created as part of my CS2 practice to strengthen my understanding of object-oriented programming through a larger hands-on application rather than isolated examples.
