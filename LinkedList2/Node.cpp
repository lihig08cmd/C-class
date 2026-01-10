/*  this is Node.cpp   that I got from >>>> Yuvraj   */

#include "Node.h"

// Creates a node and initializes pointers
Node::Node(Student* s) {
    student = s;
    next = nullptr;
}

// Deletes the stored student
Node::~Node() {
    delete student;
}

// Returns the next node
Node* Node::getNext() {
    return next;
}

// Returns the student pointer
Student* Node::getStudent() {
    return student;
}

// Sets the next node pointer
void Node::setNext(Node* n) {
    next = n;
}
