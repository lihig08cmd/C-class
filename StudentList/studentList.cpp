/*
  Student List
  kjfbeugeugeg

  Lihi Gavrielov
  10/  /25     */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// defining the struct  
struct Students {
  char firstName[80];
  char lastName[80];
  int id;
  float gpa;
};

// functions prototype
void add(vertax<Students*>students);
void print(vertax<Students*>students);
void delete_fun(vertax<Students*>students);
void quit(vertax<Students*>students);


int main(){
  //vercor of students
  vertax<Students*> students;
  
  while(true){
    // user input
    char input[80];
    cout << "Enter Add, Print, Delete, or Quit: ";
    cin >> input;

    // call the add function
    if(input == "Add"){
      add(students);
    }
    //call the print function
    else if(input =="Print"){
      print(students);
    }
    // call the delete function
    else if(input == "Delete"){
      delete_Fun(students);
	}
    // call the quit function
    else if(input == "Quit"){
      cout << "Bye!!" << endl;
      // quit the progrem and delete all the students
    }
    else{
      cout << "Try again. Enter either Add, Print, Delete, or Quit: ";
      cin >> input;
    }

  }
  return 0;
}



void add(){
  // add another student to the students struct
  Students* addNewS = new Students();

  cout <<"Enter first name: ";
  cin >> addNewS.firstName;

  cout <<"Enter last name: ";

  cout<< "Enter student ID: ";

  cout << "Enter student GPA: ";
  student.push_back(addNewS);

}

void print(){
  // print out everything that is in the struct
  if (students.empty()){
    cout <<"No students";
  }

  //print all the students and their info (GPA only with 2 decimals)
  for (...)
    // for every studetn print their info
  
}

void delete_fun(){
  // ask for the id then delete from struct

}

void quit(){
  // quit and exit

}
