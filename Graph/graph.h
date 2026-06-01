// this is graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstring>
using namespace std;

class graph{
 private:
  // max amount of vertices
  static const int MAX = 20;

  //stores vertex labels
  char vertices[MAX][20];

  //adjacency table
  int adj[MAX][MAX];

  //current number of vertices
  int vertexCount;

  //finds index of a vertex
  int findVertex(char label[]);

 public:
  //constructor
  graph();

  void addVertex();
  void addEdge();
  void removeVertex();
  void removeEdge();
  void shortestPath();
  void printGraph();

};
#endif
