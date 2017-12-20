#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include "Instructor.h"

class Course {
public:
  // initializes Object's Course name to " "
  // initializes Object's Instructor's name to " "
  // initializes Object's Number of Exams to 0
  // initializes Object's Maximum number of seats to 0
  Course ();
  // @param m - set the value for Course name
  // @param n - set the value for Instructor's name
  // @param e - set the value for number of number of Exams
  // @param s - set the value for Maximum number of Seats
  // Number of Students in Course is set by default to 0
  Course (string m, string n, int e, int s);
  // @return - Course's Name as a string
  string getCourseName () const;
  // @param m - set the value for Course name
  void setCourseName (string m);
  // @return - Course's Instructor as an Instructor type
  Instructor& getInstructor ();
  // @return - Course's Instructor as a string
  Instructor& setInstructor (string n);
  // overload Assignment operator
  Course& operator = (const Course& c);
  // Copy Constructor
  Course (const Course& c);
  // Destructor, deletes Students elements and array
  ~Course ();
  // @param s, Adds a new student object to the students array
  // checks if numstudents less tha Capacity-1 calls grow function to expand Array
  void addStudent (Student& s);
  // @param s - takes a student object and displays the students data
  void displayStudentsData (Student &s);
  // overload the [] operator, returns the index of the students' Array
  Student& operator[] (int index);
  // overload the >> operator for iostream
  friend istream& operator >> (istream& instream, Course& c);
  // overload the << operator for iostream
  friend ostream& operator << (ostream& outstream, Course& c);
  //overload the << operator for fstream, requires <fstream> library
  friend ofstream& operator << (ofstream& outstream, Course& c);
  // @returns int value for the number of Exam grades in the students object
  int numGrades();
  // @returns int of Capacity of elements in the students array
  int getMaxSeats ();
  // param int- sets Capacity of element in students array
  void setMaxSeats (int Capacity);
  //*** F NOT WORKING PROPERLY *** Function supposed to renove a student from the student array
  void removeStudent (Student** s, int index);
  // students Array
  Student **students {};
  // @return int value for number of students in the Students' array
  int getNumStudents () {return numStudents;}
private:
  int numExams;
  string name;
  Instructor inst {""};
  int CAP;
  int numStudents;
  void grow();
};

#endif
