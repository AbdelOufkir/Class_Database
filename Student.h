#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Student {
public:
  // initializes Object's first name to " "
  // initializes Object's last name to " "
  Student ();
  // @param f - set the value for first name
  // @param l - set the value for last name
  // initializes Array int of grades
  // size of Array set to 5, number of exams is set to 0
  Student (string f, string l);
  // @param f - set value for first name
  void setFirst (string f);
  // @param l - set value for last name
  void setLast (string l);
  // @returns first name as a string
  string getFirst () const;
  // @returns last name as a string
  string getLast () const;
  // @param f set value for first name
  // @param l set value for last name
  void setNames (string f, string l);
  // @returns first and last name as a string
  string getNames () const;
  // destructor deletes array of grades
  ~Student ();
  // Copy Constructor
  Student (const Student& s);
  // overload assignment operator
  Student& operator= (const Student& s);
  // @param num- adds an int value to the array of grades
  void addGrade (int num);
  // @param num - removes an int value from the array of grades
  void removeGrade (int num);
  // displays the Array of grades to the IO console
  void outputGrades ();
  // $returns a floating point value for the GPA of grades for each students
  double calculateGpa ();
  // displays name, grades and GPA for each students
  void outputData ();
  // @param e - set value for number of exams in the grades array
  void setNumExams (int e);
  // @returns int value for number of exams in the grades array
  int getNumExams () const ;
  // overload [] operator and returns index value in the grades array
  int operator[] (int index);
  // overloads == operator, checks if first and last name are identical
  bool operator == (const Student& s) const;
  // overloads >> operator for iostream
  friend istream& operator>> (istream& instream, Student& s);
  // overload << operator for iostream
  friend ostream& operator<< (ostream& outstream, Student& s);
  // overload << for fstream - requires <fstream> library
  friend ofstream& operator<< (ofstream& outstream, Student*& s);
  // pointer to int array of grades
  int *grades;
private:
  string first;
  string last;
  int CAP;
  int numExams;
};

#endif
