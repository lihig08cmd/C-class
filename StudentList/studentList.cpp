/*
  Student List

  Lihi Gavrielov
  11/3/25     */

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;

// defining the struct  
struct Students {
  char firstName[80];
  char lastName[80];
  int id;
  float gpa;
};

// functions prototype
void add(vector<Students*>& students);
void print(vector<Students*>& students);
void delete_fun(vector<Students*>& students);

int main(){
  //vercor of students
  vector<Students*> students;
  
  while(true){
    // user input
    char input[80];
    cout << "Enter Add, Print, Delete, or Quit: ";
    cin >> input;

    // call the add function
    if(strcmp(input, "Add") == 0 || strcmp(input, "add") == 0){
      add(students);
    }
    //call the print function
    else if(strcmp(input, "Print") ==0 || strcmp(input, "print") == 0){
      print(students);
    }
    // call the delete function
    else if(strcmp(input, "Delete") == 0|| strcmp(input, "delete") == 0){
      delete_fun(students);
	}
    // call the quit function
    else if(strcmp(input, "Quit") == 0 || strcmp(input, "quit") ==0 ){
      cout << "Bye!!" << endl;
      return 0;
    }
    else{
      cout << "Try again." << endl;
    }

  }
  return 0;
}


// add a new student to the vector
void add(vector<Students*>& students){
  cout << "Adding a new student" << endl;

  // 
  Students* addNewS = new Students();

  // asks the user for info on the new student
  cout <<"Enter first name: ";
  cin >> addNewS->firstName;

  cout <<"Enter last name: ";
  cin >> addNewS->lastName;

  cout<< "Enter student ID: ";
  cin >> addNewS -> id;
  
  cout << "Enter student GPA: ";
  cin >> addNewS -> gpa;

  // adding the new student to teh vector
  students.push_back(addNewS);

  cout <<"Added the new student!!!" << endl;

}

void print(vector<Students*>& students){
  //check if there is students
  if (students.empty()){
    cout <<"No students" << endl;
    return;
  }

  //print all the students and their info (GPA only with 2 decimals)
  
  for (Students* student: students) {
    cout << student->firstName<< ' ' << student->lastName << ", "<< student -> id << ", " << fixed << setprecision(2) << student ->gpa << endl;
  }
}
void delete_fun(vector<Students*>& students){
  // check if there are any students
  if(students.empty()){
    cout <<"No students to delete" << endl;
    return;
  }

  // asking the user for the ID to delete
  int deleteID;
  cout <<"Enter students ID to delete: ";
  cin >> deleteID;

  // looking for the student using the ID
  for (auto it = students.begin(); it != students.end(); it++){
    if ((*it) ->id == deleteID){
      //delete it
      delete *it;
      students.erase(it);
      cout<< "Student deleted" << endl;
      return;
    }
  }

}
