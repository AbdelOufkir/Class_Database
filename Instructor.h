#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include<iostream>
#include<string>
using namespace std;

class Instructor {
  public:
    //initializes Instructor default Constructor to " ", " "
    Instructor ();
    // @param n - set the value for the name of the instructor
    Instructor (string n);
    // @param n - set value for the name of the instructor
    // @parwam d - set the value for the department
    Instructor (string n, string d);
    // @returns name of instructor as string
    string getName () const;
    // @param n - set value for name of instructor
    void setName (string n);
    // @return department of instructor as string
    string getDept () const;
    // @param d - set value for department
    void setDept (string d);
  private:
    string name;
    string department;
};

#endif
