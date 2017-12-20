#include "Course.h"

Course::Course():Course("","",0,0) {}

Course::Course (string m, string n, int e, int s) : name(m), inst(n), numExams(e), CAP(s), numStudents(0) {
    students = new Student *[CAP];
}

string Course::getCourseName () const {return name;}

void Course::setCourseName (string m) {name = m;}

Instructor& Course::getInstructor () { return inst;}

Instructor& Course::setInstructor (string n) {inst.setName(n);}

Course& Course::operator = (const Course& c) {
    if (this != &c) {
      if (students != nullptr)
        delete [] students;
        name = c.name;
        inst = c.inst;
        CAP = c.CAP;
        numStudents = c.numStudents;
        students = new Student*[CAP];
        for (int i=0; i<numStudents; i++)
            students[i] = c.students[i];
          }
    return *this;
}

Course::Course (const Course& c) {
    name = c.name;
    inst = c.inst;
    CAP = c.CAP;
    numStudents = c.numStudents;
    students = new Student *[CAP];
    for (int i=0; i<numStudents; i++) {
      students[i] = c.students[i];
      }
}

Course::~Course () {
    for (int i=0; i<numStudents; i++){
          delete students[i];
        }
      delete [] students;
}

int Course::numGrades () {return (*students)->getNumExams();}

void Course::grow () {
  CAP = (CAP*2)+1;
  Student **temp = new Student*[CAP]();
    for (int i=0; i<numStudents; i++) {
     temp[i] = students[i];
    }
    delete [] students;
    students = temp;
}

void Course::addStudent (Student& s) {
  if (numStudents >= CAP-1){
    grow();
    }
  students[numStudents++] = new Student(s);
  s.setNumExams(numExams);
}


void Course::displayStudentsData (Student& s) {
  cout << "Course name is: " << this->getCourseName() << endl;
  cout << "Instructor's name is: " << this->inst.getName() << endl;
  ;
}

Student& Course::operator[] (int index) {
  if ((index < 0) || (index > numStudents)) {
    cout << "index not whithin range, try again!" << endl;
    }
    for (int i=0; i<numStudents; i++) {
      if (index == i)
        return *students[i];
    }
}

istream& operator>> (istream& instream, Course& c) {
        string course, instructor;
        int examination, seats;

        cin.ignore();
        cout << "Enter the course Title: ";
        getline(cin,course);
        cout << "Enter the name of the instructor: ";
        getline(cin, instructor);
        cout << "Enter the number of Examination: ";
        cin >> examination;
        cout << "Enter the maximum Number of Seats: ";
        cin >> seats;

        c.setCourseName(course);
        c.setInstructor(instructor);
        c.numExams = examination;
        c.CAP = seats;
        c.students = new Student*[c.CAP];

  return instream;
}

ostream& operator << (ostream& outstream, Course& c) {
    outstream << c.getCourseName() << " Inst: " <<setw(20) << left << c.getInstructor().getName()
      << " Enrolled: "<< setw(5) << left << c.numStudents << " MaxSeats: " << setw(5) << left << c.CAP << endl;
  return outstream;
}

ofstream& operator<< (ofstream& outstream, Course& c) {
   cout << "Course:" << "|" << c.getCourseName() << "|" <<
      c.getInstructor().getName() << "|" << c.numGrades() << "|" <<
      c.getNumStudents() << "|" << c.getMaxSeats() << endl;
        for (int i=0; i<c.getNumStudents(); i++){
          cout << c.students[i] << ",";
          cout << endl;
        }
  return outstream;
 }

 int Course::getMaxSeats() {return CAP;}

 void Course::setMaxSeats (int Capacity) {
      if (Capacity <= numStudents) {
        cout << "Warning, number of Students is greater than Max Seats, Adjust the number accordingly!" << endl;
      }
      else {
        CAP = Capacity;
        Student **temp = new Student*[CAP]();
        for (int i=0; i<numStudents; i++) {
          temp[i] = students[i];
        }
        delete []students;
        students = temp;
      }
 }

 //void removeStudent (Course& c, Student** s, int index) {
  //     for (int i=index; i<c.numStudents; i++) {
  //           c.students[i] = c.students[i+1];
    //   }
    //   c.numStudents--;
