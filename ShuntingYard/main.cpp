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
int order(char c);//operator precendece
bool isOperators(char c);//check if its a opeator 
Node* buildTree(Queue &postfix);  //build expression tree from postfix 
void printPrefix(Node* root);  //  this function prints the prefix
void printInfix(Node* root);  //  this function prints the infix


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
      // peek operators until '(' is found
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
      while(!operators.isempty()&&isOperators(operators.peek()->getValue())&&order(operators.peek()->getValue()) >= order(current)){
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
  
  //to copy postfix
  Queue postfixCopy;

  cout << "Postfix: ";

  // go through original queue
  while(!output.isempty()){
    //remove front node from output queue
    Node* temp = output.dequeue();

    //add to new queue 
    postfixCopy.enqueue(temp);

    //print postfix expresstion
    cout << temp->getValue() << " ";
  }
  cout << endl;

  // bulid tree
  Node* root = buildTree(postfixCopy);

  //printing from tree
  cout << "Infix: ";
  printInfix(root);
  cout << endl;

  cout<<"Prefix: ";
  printPrefix(root);
  cout << endl;

  return 0;
}

int order(char c){
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

Node* buildTree(Queue &postfix){
  Stack stack;

  // go through postfix one token at a time
  while(!postfix.isempty()){

    // take next item
    Node* current = postfix.dequeue();
    char value = current->getValue();

    //if number push
    if(value >= '0' && value <= '9'){
      //numbers become leaf
      stack.push(current);
    }

    //operator
    else{
      // pop two nodes
      Node* right  = stack.pop();
      Node* left = stack.pop();

      // connect operator
      current->setLeft(left);
      current->setRight(right);

      //push back onto stack
      stack.push(current);
    }

  }
  // the last node left is the root
  return stack.pop();
}

void printPrefix(Node* root){
  if(root==NULL){
    return;
  }

  //left, right, root
  cout<<root->getValue() << " "; //print root
  printPrefix(root->getLeft());
  printPrefix(root->getRight());
  
}


void printInfix(Node* root){
  if(root==NULL){
    return;
  }

  // left, root, right
  printInfix(root->getLeft()); //go left first
  cout << root->getValue() << " "; //print root
  printInfix(root->getRight());  // go right
}
