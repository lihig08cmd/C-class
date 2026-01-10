/* this is Node.h   that I got from >>>> Yuvraj  */


#ifndef NODE_H
#define NODE_H

#include "Student.h"

// Node class used in a linked list
class Node {
private:
    Student* student;
    Node* next;

public:
    // Creates a node with a student pointer
    Node(Student*);

    // Destroys the node
    ~Node();

    // Returns the next node
    Node* getNext();

    // Returns the student pointer
    Student* getStudent();

    // Sets the next node pointer
    void setNext(Node*);
};

#endif
