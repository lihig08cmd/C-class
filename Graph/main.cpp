#include "Graph.h"

int main(){
  graph graph;

  char command[20];
  while(true){
    cout << endl;
    cout << "AV - add vertex" << endl;
    cout << "AE - add edge" << endl;
    cout << "RV - remove vertex" << endl;
    cout << "RE - remove edge" << endl;
    cout << "FSP - find shortset path" << endl;
    cout << "P - print" << endl;
    cout << "Quit" << endl;

    cout << "Enter command: ";
    cin >> command;
    cout << endl;


    if(strcmp(command, "AV")==0){
      graph.addVertex();
    }
    else if(strcmp(command, "AE")==0){
      graph.addEdge();
    }
    else if(strcmp(command, "RV")==0){
      graph.removeVertex();
    }
    else if(strcmp(command, "RE")==0){
      graph.removeEdge();
    }
    else if(strcmp(command, "FSP")==0){
      //graph.shortestPath();
    }
    else if(strcmp(command, "P")==0){
      graph.printGraph();
    }
    else if(strcmp(command, "QUIT")==0){
      break;
    }
  }
  return 0;
}
