#include"Student.h"

Student::Student (): Student (" ", " ") {}
Student::Student (string f, string l): first(f), last(l), CAP(5), numExams(0) {
  grades = new int[CAP];
  }
void Student::setFirst (string f) {first =f;}
void Student::setLast (string l) {last =l;}
string Student::getFirst () const { return first;}
string Student::getLast () const { return last;}
void Student::setNames (string f, string l) {
  cout << "Enter First name: ";
  cin >> f;
  cout << "Enter Last name: ";
  cin >> l;
  first = f, last = l;
  }
string Student::getNames () const {return first + " " + last;}

Student::~Student () {
delete [] grades;
}

Student::Student (const Student& s) {
    first = s.first;
    last = s.last;
    CAP = s.CAP;
    numExams = s.numExams;
    grades = new int[CAP]();
      for (int i=0; i<numExams; i++){
        grades[i] = s.grades[i];
      }
}

Student& Student::operator= (const Student& s) {
      if (this != &s) {
        first = s.first;
        last = s.last;
        if (grades != nullptr)
          delete [] grades;
          CAP = s.CAP;
          numExams = s.numExams;
          grades = new int [CAP]();
          for (int i=0; i<numExams; i++) {
            grades[i] = s.grades[i];
          }
        }
    return *this;
}


void Student::addGrade (int num) {
  if (numExams <= CAP) {
    grades[numExams++] = num;
    }
  else
  cout << "Max Capacity Reached!";
}

void Student::removeGrade (int num) {
  for (int i=num-1; i<numExams; i++){
    grades[i] = grades[i+1];
    }
  numExams--;
}

void Student::outputGrades () {
  for (int i=0; i<numExams; i++)
  cout << i+1 << ": "<< grades[i] << endl;
}

double Student::calculateGpa (){
  double sum =0;
  for (int i=0; i<numExams; i++) {
     sum += static_cast<double>(grades[i]);
  }
  return sum/numExams;
}

void Student::outputData () {
      cout << this->getNames();

        for (int i=0; i<numExams; i++){
          cout << grades[i] << " ";
          }
      cout <<"GPA IS: "<< this->calculateGpa() << endl;
    }

void Student::setNumExams (int e) { numExams = e;}

int Student::getNumExams () const { return numExams;}

int Student::operator[] (int index) {
    if ((index < 0) || (index>numExams)) {
      cout << "Index not within Range, try again!" << endl;
      }
      for (int i=0; i<numExams; i++){
        if (index == i)
          return grades[i];
  }
}

bool Student::operator== (const Student& s) const {
  return ((first == s.first) && (last == s.last));
  }

istream& operator >> (istream& instream, Student& s) {
     string first, last;
     int grade;
     cin.ignore();

     cout << "Enter First name: ";
     getline(cin,first);

     cout << "Enter Last name: ";
     getline(cin, last);

     s.setFirst(first);
     s.setLast(last);
     int CAP = s.CAP;
     int numExams = s.numExams;

     s.grades = new int[CAP]();

     do {
       cout << "Enter a grade or -1 when done: ";
       cin >> grade;
       if (grade > -1 && grade<= 100) {
            s.addGrade(grade);
            }
        else if (grade == -1){
            cin.ignore();
          break;
          }

        else {
            cout << "Grades must be between 0 and 100." << endl;
            continue;
          }
      } while (grade != -1);
  return instream;
}

ostream& operator<< (ostream& outstream, Student& s) {

   outstream << setw(20) << left<< s.getNames() << " "  <<
         "GPA: " << setw(10) << left << s.calculateGpa() << " " << "Grades: ";
          for (int i=0; i<s.numExams; i++){
            outstream << s.grades[i] << " ";
            }


  return outstream;
}

ofstream& operator<< (ofstream& outstream, Student*& s) {

    cout << "Student|" << s->getFirst() << "|" << s->getLast() <<
      "|";
      for (int i=0; i<=s->getNumExams(); i++) {
        cout << s->grades[i] << ",";
      cout << endl;
      }
  return outstream;
}
