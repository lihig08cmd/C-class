#include "Graph.h"

graph::graph(){
  vertexCount = 0;

  //set every edge to 0
  for(int i=0; i<MAX; i++){
    for(int j=0; j<MAX; j++){
      adj[i][j] = 0;
    }
  }
}

int graph:: findVertex(char label[]){
  for(int i=0; i<vertexCount; i++){
    if(strcmp(vertices[i], label)==0){
      return i;
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
    return;
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

//remove edge between 2 vertices
void graph::removeEdge(){
  char start[20];
  char end[20];

  cout << "Enter starting vertex: " << endl;
  cin >> start;

  cout << "Enter ending vertex: " << endl;
  cin >> end;

  int startIndex = findVertex(start);
  int endIndex = findVertex(end);

  if(startIndex == -1 || endIndex == -1){
    cout <<"Vertex not found" << endl;
    return;
  }

  //setting edge to 0 removes it
  adj[startIndex][endIndex] = 0;
  cout << "Edge removed" << endl;
}

//remove vertex and all edges connected to it
void graph::removeVertex(){
  char label[20];

  cout << "Enter vertex label to remove: " << endl;
  cin >> label;

  int index = findVertex(label);

  if(index == -1){
    cout << "Vertex not found" << endl;
    return;
  }

  //shift labels left
  for(int i=index; i < vertexCount-1; i++){
    strcpy(vertices[i], vertices[i+1]);
  }

  //shift row upword
  for(int i= index; i<vertexCount-1; i++){
    for(int j=0; j<vertexCount; j++){
      adj[i][j] = adj[i+1][j];
    }
  }

  //shift colums left
  for(int i=0; i < vertexCount; i++){
    for(int j=index; j<vertexCount-1; j++){
      adj[i][j] = adj[i][j+1];
    }
  }
  vertexCount--;
  cout <<"vertex removed"<< endl;
}

void graph::printGraph(){
  cout << "   ";

  //top labels
  for (int i=0; i<vertexCount; i++){
    cout << vertices[i] << " ";
  }
  cout << endl;

  //print rows
  for(int i=0; i<vertexCount; i++){
    cout << vertices[i] << " ";
    for(int j=0; j <vertexCount; j++){
      cout << " " << adj[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

//uses Dijksta's algorithem to find shortest path
void graph::shortestPath(){
  char start[20];
  char end[20];

  cout <<"Enter staring vertex: " << endl;
  cin >>start;

  cout <<"Enter ending vertex: " << endl;
  cin >>end;

  int startIndex = findVertex(start);
  int endIndex = findVertex(end);

  if(startIndex == -1 || endIndex == -1){
    cout << "Vertex not found" << endl;
    return;
  }

  //distance array
  int dist[MAX];
  bool visited[MAX];
  int prev[MAX];

  //initialize arrays
  for(int i=0; i<vertexCount; i++){
    dist[i] = INT_MAX;
    visited[i] = false;
    prev[i]=-1;
  }

  //distance to self is 0
  dist[startIndex] = 0;

  //main Dijktra loop
  for(int count = 0; count <vertexCount-1; count++){
    int smallest = INT_MAX;
    int current = -1;

    //find closest unvisited vertex
    for(int i=0; i<vertexCount; i++){
      if(!visited[i] && dist[i] < smallest){
	smallest = dist[i];
	current = i;
      }
    }

    //no reachable vertex
    if(current == -1){
      break;
    }

    visited[current] = true;

    //check neighbors
    for(int neighbor=0; neighbor<vertexCount; neighbor++){
      //edge exists
      if(adj[current][neighbor] > 0){
	int newDist = dist[current]+adj[current][neighbor];

	//shorter path found
	if(newDist < dist[neighbor]){
	  dist[neighbor] = newDist;
	  prev[neighbor] = current;
	}
      }
    }
  }

  //no path exists
  if(dist[endIndex] == INT_MAX){
    cout << "No path exists" << endl;
    return;
  }
  //rebuilding path
  int path[MAX];
  int pathSize = 0;

  int current = endIndex;
  while(current != -1){
    path[pathSize] = current;
    pathSize++;
    current = prev[current];
  }

  //print path backwords
  cout << "Shortest Path: ";
  for(int i= pathSize-1; i>=0; i--){
    cout << vertices[path[i]];
    if(i>0){
      cout << " -> ";
    }
  }
  cout << endl;

  cout << "Total weight: " << dist[endIndex]<<endl;
}
