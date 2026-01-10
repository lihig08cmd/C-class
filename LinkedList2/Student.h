/* this is student.h */

#ifndef STUDENT_H
#define STUDENT_H

class Student{
 private:
  char first[80];
  char last[80];
  int id;
  float gpa;

 public:
  Student();

  int getID();
  float getGPA();
  void print();

};
#endif
