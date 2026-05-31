#include "Graph.h"

Graph::Graph(){
  vertexCount = 0;

  //set every edge to 0
  for(int i=0; i<MAX; i++){
    for(int i=0; j<MAX; j++){
      adj[i][j] = 0;
    }
  }
}

int graph:: findVertex(char label[]){
  for(int i=0; i<vertexCount; i++){
    if(strcmp(vertices[i], label)==0){
      return i ;
    }
  }
  return -1;
}

//adds new vertex to the graph
void graph::addVertex(){
  if(vertexCount >= MAX){
    cout << "Graph is full" << endl;
    return;
  }
  char label[20];

  cout <<"Enter vertex label: "<< endl;
  cin >>label;

  //checking if vertex already exists
  if(findVertex(label) != -1){
    cout << "Vertex already extits!" << endl;
    retrun;
  }

  //copy label into array
  strcpy(vertices[vertexCount], label);
  vertexCount++;

  cout << "Vertex added" << endl;
}

// adds directed weighted edge
void graph::addEdge(){
  char start[20];
  char end[20];
  int weight;

  cout << "Enter starting vertex: " << endl;
  cin >> start;

  cout << "Enter ending vertex: " << endl;
  cin >> end;

  cout << "Enter weight: " << endl;
  cin >> weight;

  int startIndex = findVertex(start);
  int endIndex = findVertex(end);

  if(startIndex == -1 || endIndex == -1){
    cout << "Vertex not found" << endl;
    return;
  }
  adj[startIndex][endIndex] = weight;
  cout << "Edge added" << endl; 
}
