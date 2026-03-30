// main.cpp of Shunting Yard
#include <iostream>
#include <cstring>
#include "Node.h"
using namespace std;

struct Stack{

  Node* head = NULL;

  
  //push new node into stack
  void push(Node* newNode){
    newNode->setNext(head);
    //update head
    head = newNode;
  }

  //pop head node from stack
  char pop(){
    if(head==NULL){
      return NULL;
    }

    Node* temp = head;
    head = head->getNext();
    temp->setNext(NULL);
    return temp;

  }

  //return the head (not pop it)
  char peek(){
    return head;
  }

  //check if stack is empty 
  bool isempty(){
    return head==NULL;
  }

};

struct Queue{

  // REMOVE from
  Node* front = NULL;
  // ADD to
  Node* rear = NULL;

  // add to back of queue
  void enqueue(Node* newNode){
    newNode->setNext(NULL);

    // if queue is empty
    if(rear == NULL){
      front = newNode;
      rear = newNode;
    }
    else{
      rear->setNext(newNode);
      //update rear
      rear = newNode;
    }
  }

  //remove from front
  Node* dequeue(){
    //if empty nothing to remove
    if(front==NULL){
      return NULL;
    }

    //save current front
    Node* temp = front;
    //move front forward
    front = front->getNext;

    //if queue becomes empty
    if(front ==NULL){
      rear = NULL;
    }

    // disconnect node
    temp->setNext(NULL);
    //retrun removed node
    return temp;
  }

  //check queue is empty
  bool isempty(){
    return front == NULL;
  }

};

// function prototype



int main(){



  return 0;
}
