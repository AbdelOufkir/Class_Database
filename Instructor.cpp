#include "Instructor.h"

    Instructor::Instructor (): Instructor (" "," ") {}

    Instructor::Instructor (string n): name(n) {}

    Instructor::Instructor (string n, string d): name(n), department(d) {}

    string Instructor::getName () const {return name;}

    void Instructor::setName (string n) {name = n;}

    string Instructor::getDept () const {return department;}

    void Instructor::setDept (string d) {department = d;}
