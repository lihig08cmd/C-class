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
  Node* pop(){
    if(head==NULL){
      return NULL;
    }

    Node* temp = head;
    head = head->getNext();
    temp->setNext(NULL);
    return temp;

  }

  //return the head (not pop it)
   Node* peek(){
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
    front = front->getNext();

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
int precedence(char c);//operator precendece
bool isOperators(char c);//check if its a opeator 
Node* buildTree(Queue &output);  //build expression tree from postfix 
void printPrefix(Node* root);  //  this function prints the prefix
void printInfix(Node* root);  //  this function prints the infix
void printPostfix(Node* root);  // this function prints the postfix

int main(){
  char input[100];
  cout<< "Enter expresstion: " << endl;
  cin.getline(input, 100);

  Queue output;
  Stack operators;

  //SHUNTING YARD!!!!!!!!!!!!!!
  //go through each charactor
  for(int i=0; i<strlen(input); i++){
    char current = input[i];

    //skip spaces
    if(current == ' '){
      continue;
    }

    // if numbers
    if(current >= '0' && current <='9'){
      //numbers go derectly to output
      output.enqueue(new Node(current));
    }

    //left parenthesis
    else if(current=='(' ){
      //push it to stack 
      operators.push(new Node(current));
    }

    //right parenthesis
    else if(current == ')' ){
      // pop operators until '(' is found
      while(!operators.isempty() && operators.peek()->getValue() !='('){
	// move operators to output
	output.enqueue(operators.pop());
      }
      //remove '('
      operators.pop();
    }

    //operator
    else if(isOperators(current)){
      // while is stack not empty and top is operator and top had higher or same prioraty 
      while(!operators.isempty()&&isOperators(operators.peek()->getValue())&&precedence(operators.peek()->getValue()) >= precedence(current)){
	//move stronger operator to output first
	output.enqueue(operators.pop());
      }
      //push current operator
      operators.push(new Node(current));
    }
  }

  //empty stack
  while(!operators.isempty()){
    output.enqueue(operators.pop());
  }

  //copy postfix
  Queue postfixCopy;
  
}

int precedence(char c){
  if(c=='+' || c=='-'){
    return 1;
  }
  if(c=='*' || c=='/'){
    return 2;
  }
  if(c=='^'){
    return 3;
  }
  return 0;
}

bool isOperators(char c){
  return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

  
