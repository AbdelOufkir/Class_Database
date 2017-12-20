#include "Course.h"
#include <fstream>
#include <sstream>

const string inFile = "database.txt";
const string outFile = "database.txt";

int maxSize = 100;
int numCourses = 0;
Course *Courses = new Course[maxSize];

// @param Courses Array/Pointer and int num of Courses
// Function saves Array elements to databas.txt file
//******* FUNCTION NOT WORKING PROPERLY DUE TO OFSTREAM OVERLOAD PROBLEM!
void save(Course* Courses, int numCourses) {

  ofstream fout(outFile);
  for (int i=0; i<numCourses; i++) {
    fout << Courses[i];
  }
  fout.close();
}

// @param Courses Array and int num of numCourses
// Function loads the data from file database.text
// Function parses data and saves it into Courses' and students' objects
  void load (Course Courses[], int& numCourses) {

    ifstream fin (inFile);
    string line, FirstField, courseNumber, instName, grades, examNumber,
            grade, enrolledNumber, seatsNumber, studentFirst, studentLast;

    while (getline(fin,line)) {
      istringstream ss(line);
      getline(ss, FirstField, '|');
        if (FirstField == "Course") {
          getline(ss, courseNumber, '|');
          getline(ss,instName,'|');
          getline(ss,examNumber,'|');
          getline(ss,enrolledNumber, '|');
          getline(ss,seatsNumber, '|');
          Course c(courseNumber, instName, stoi(examNumber), stoi(seatsNumber));
          Courses[numCourses++] = c;
            }
        else if (FirstField == "Student") {
          getline(ss, studentFirst,'|');
          getline(ss, studentLast, '|');
          getline(ss, grades, '|');
          Student s(studentFirst, studentLast);
          istringstream commaparser(grades);
            while(getline(commaparser, grade, ',')) {
            s.addGrade(stoi(grade));
            }
          Courses[numCourses-1].addStudent(s);
          }
        }
  fin.close();
  }

// @param Course Object; function checkes if Array's capacity is not exhausted
// + appends courses objects into array
  void addNewCourse (Course& C) {
    if (numCourses >= maxSize) {
      cout << "Maximum Number of Courses reached! \n";
      }
    else {
      cin >> C;
      Courses[numCourses++] = C;
      }

  }

// @param Course pointer/array, and int Index
// function removes specific course from array
// courses' index is selected by user
  void RemoveCourse (Course* Courses, int index) {
      string temp = Courses[index-1].getCourseName();
        for (int i=index-1; i<numCourses; i++) {
          Courses[i] = Courses[i+1];
        }
        cout << temp << " is removed";
      numCourses--;

  }

// @param Course pointer/array and int Index
// function lists the data of the students object
// specified course is selected by user
  void listStudentsinClass (Course* Courses, int index) {
        for (int i=0; i<(Courses[index-1].getNumStudents()); i++) {
          cout << i+1 << ": " << *(Courses[index-1].students[i]);
        cout << endl;
        }
  }

// @param Student object; Function displays the grades of a specified student
  void listStudentGrades (Student* s) {
    s->outputGrades();
  }

// @param student object, int index and int new grades
// function changes the value of a specified grade of a specified student
// student, index and the new value of the grade are specified by the user
  void replaceGrade (Student* s, int index, int& newGrade) {
    for (int i=0; i<Courses->numGrades(); i++){
        s->grades[index] = newGrade;
        }
        cout << "Grade Replaced" << endl;
  }

// @param student object and int grade to remove
// function removes a specified grade from the grade list
  void removeGrade (Student *s, int gradeRemove) {
    for (int i=0; i<Courses->numGrades(); i++){
        s->grades[gradeRemove] = 0;
    }
  }


int main () {


  cout.setf(ios::fixed);
  cout.precision(2);
  cout << "\n\n";
  cout << "=================================================================\n";
  cout << "Project I  Fall 2017   :   A. Oufkir\n";
  cout << "=================================================================\n";

  int option, studentMenu, studentToRemove, studentToModify,studentIndex, updateGrade, newGradeVal, gradeRemove;
  int index;
  load(Courses, numCourses);
  Course C;
  Student S {};


  do {
    cout << "=================================================================\n";
    cout << "MAIN MENU \n";
    cout << "=================================================================\n\n";
    cout << "1. Display Courses \n";
    cout << "2. Add Course \n";
    cout << "3. Remove Course \n";
    cout << "4. Modify Course\n";
    cout << "5. Exit Program \n\n";
    cout << "Select an Option: ";
    cin >> option;

    switch(option) {
      case 1:
            cout << "\n---------------------------------------------------------------\n";
            cout << "Display Courses\n";
            cout << "---------------------------------------------------------------\n\n";
                for (int i=0; i<numCourses; i++) {
                  cout << i+1  << ": " << Courses[i];
                  }
        break;
      case 2:
            cout << "\n-----------------------------------------------------------------\n";
            cout << "Add New Course:\n";
            cout << "-----------------------------------------------------------------\n";
              addNewCourse(C);
        break;
      case 3:
            cout << "\n-----------------------------------------------------------------\n";
            cout << "Remove Course:\n";
            cout << "-----------------------------------------------------------------\n";
              for (int i=0; i<numCourses; i++) {
                    cout << i+1 << ": " << Courses[i];
                  }
                do {
                    cout << "\nSelect a Course to Remove: ";
                    cin >> index;
                    if (index <= 0 || index>numCourses)
                      cout << "Index Not whithin Range, Try Again!\n";
                    else {
                        RemoveCourse(Courses, index);
                        break;
                        }
                    }while (true);
        break;
      case 4:
            cout << "\n-----------------------------------------------------------------\n";
            cout << "Modify Course:\n";
            cout << "-----------------------------------------------------------------\n";
              for (int i=0; i<numCourses; i++) {
                  cout << i+1 << ": " << Courses[i];
                  }
                cout << "\nSelect a Course to Modify:";
                cin >> index;

                cout << "\n=================================================================\n";
                cout << "Course Menu:\n";
                cout << "=================================================================\n";

              do {
                    cout << "-----------------------------------------------------------------\n";
                    cout << Courses[index-1];
                    cout << "-----------------------------------------------------------------\n";
                    if ((Courses[index-1].numGrades()) == 0)
                     {
                      cout << "\nNo Students Erolled.\n";
                      }
                    else {
                      listStudentsinClass(Courses, index);
                      }
                      cout << "\n=================================================================\n";
                      cout << "Student Menu:\n";
                      cout << "=================================================================\n";
                      cout << "1. Add Student\n";
                      cout << "2. Remove Student\n";
                      cout << "3. Modify Student\n";
                      cout << "4. Main Menu\n";
                      cout << "\nSelect and Option: ";
                      cin >> studentMenu;

                        switch (studentMenu)
                          {
                            case 1:
                                cout << "\nAdd Student\n";
                                cout << "-----------------------------------------------------------------\n";
                                cin >> S;
                                Courses[index-1].addStudent(S);
                              break;
                            case 2:
                                cout << "\nRemove Student\n";
                                cout << "-----------------------------------------------------------------\n";
                                listStudentsinClass(Courses, index);
                                cout << "-----------------------------------------------------------------\n";
                                cout << "Select a Student to Remove: ";
                                cin >> studentToRemove;
                          //      Courses->removeStudent(Courses[index-1], Courses->students, studentToRemove);
                              break;
                            case 3:
                                cout << "\nModify Student\n";
                                cout << "-----------------------------------------------------------------\n";
                                listStudentsinClass(Courses, index);
                                cout << "\n-----------------------------------------------------------------\n";
                                cout << "Select a Student to Modify: ";
                                cin >> studentIndex;

                              do {
                                  cout << "\nStudent Menu:\n";
                                  cout << "=================================================================\n";
                                  cout << *(Courses[index-1].students[studentIndex-1]);
                                  cout << "\n-----------------------------------------------------------------\n\n";
                                  cout << "1.Update Grade\n";
                                  cout << "2.Remove Grade\n";
                                  cout << "3.Course Menu\n";
                                  cout << "\nSelect an Option: ";
                                  cin >> studentToModify;
                                  cout << endl;

                                   switch (studentToModify) {
                                        case 1:
                                            cout <<"\n-----------------------------------------------------------------\n";
                                            listStudentGrades(Courses[index-1].students[studentIndex-1]);
                                            cout <<"-----------------------------------------------------------------\n";
                                            cout << "\nSelect a Grade to Add/Replace: ";
                                            cin >> updateGrade;
                                            cout << "Enter a new Value: ";
                                            cin >> newGradeVal;
                                            replaceGrade(Courses[index-1].students[studentIndex-1], updateGrade-1, newGradeVal);
                                          break;
                                        case 2:
                                            cout <<"\n-----------------------------------------------------------------\n";
                                            listStudentGrades(Courses[index-1].students[studentIndex-1]);
                                            cout <<"-----------------------------------------------------------------\n";
                                            cout << "\nSelect a Grade to Remove: ";
                                            cin >> gradeRemove;
                                            removeGrade(Courses[index-1].students[studentIndex-1], gradeRemove-1);
                                          break;
                                        case 3:
                                            cout << "Back to Course Menu \n";
                                          break;
                                          default:
                                            cout <<" Invalid Input, try Again!";
                                      }
                                } while (studentToModify != 3);
                              break;
                            case 4:
                                cout << "Exit to Main Menu\n";
                              break;
                            default:
                              cout << "Not a Valid Entry, try again!\n";
                          }
                } while (studentMenu != 4);
            break;
          case 5: cout << "Exiting Program" << endl;
            break;
          default: cout << "Invalid Entry, try again!" << endl;
        }
  } while (option != 5);



  return 0;
}
