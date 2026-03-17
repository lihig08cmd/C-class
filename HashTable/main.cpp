/*
  Hash Table

  lihi Gavrielov
  3/16/2026   */


#include <iostream>
#include <cstring>
#include <fstream> //for reading files
#include <cstdlib>
#include <ctime>
#include "hashTable.h"
using namespace std;

// this function loads first names and last names from text files into arrays
void loadNames(char* firstNames[20], char* lastNames[20]);
//This function generates random students and adds them to the hash table
void generateStudents(HashTable & table, char* firstNames[20], char* lastNames[20], int num);



int main(){
  //makes random numbers diffrent each run
  srand(time(NULL));

  // create hash table
  HashTable table;

  // arrays for names
  char* firstNames[20];
  char* lastNames[20];

  // load names from files
  loadNames(firstNames, lastNames);

  while(true){
    //user input
    char input[80];
    cout << "Enter command (ADD,PRINT,DELETE,RANDOM,QUIT): " << endl;
    cin>> input;

    // if input is add
    if(strcmp(input, "ADD")==0){
      char first[20];
      char last[20];
      float gpa;

      cout <<"First name: " << endl;
      cin >>first;
      cout <<"Last name: " << endl;
      cin >>last;
      cout <<"GPA: " << endl;
      cin >> gpa;

      //create student
      Student* s= table.createStudent(first, last, gpa);

      //add to hash table
      table.addStudent(s);
    }
    else if(strcmp(input, "PRINT")==0){
      table.printTable();
    }
    else if(strcmp(input, "DELETE")==0){
      int id;
      cout<<"Enter ID " << endl;
      cin >> id;
      table.deleteStudent(id);
    }
    else if(strcmp(input, "RANDOM")==0){
      int num;
      cout<< "How many students: " << endl;
      cin >> num;
      generateStudents(table, firstNames,lastNames,num);
    }
    else if(strcmp(input, "QUIT")==0){
      break;
    }


  }

}


void loadNames(char* firstNames[20], char* lastNames[20]){

  //open files
  ifstream firstFile("firstNames.txt");
  ifstream lastFile("lastNames.txt");

  int i=0;

  char temp[50];

  //first names
  while(i<20 && firstFile.getline(temp,50)){
    firstNames[i] = new char[strlen(temp) +1];

    //copy name into array
    strcpy(firstNames[i], temp);

    i++;
  }

  firstFile.close();

  // last names
  i=0;
  while(i<20 && lastFile.getline(temp,50)){
    lastNames[i] = new char[strlen(temp)+1];
    strcpy(lastNames[i], temp);

    i++;
  }
  lastFile.close();
}


void generateStudents(HashTable & table, char* firstNames[20], char* lastNames[20], int num){
  for(int i=0; i<num; i++){
    //pick random first name
    int firstIndex = rand() %20;

    // pick random last name
    int lastIndex = rand() %20;

    //random GPA between 1.0 and 4.0
    float GPA = ((rand()%301)/100.0) + 1.0;

    // create student using HashTable function
    Student* s= table.createStudent(firstNames[firstIndex],lastNames[lastIndex],GPA);
    //add student to hash table
    table.addStudent(s);

  }
}
