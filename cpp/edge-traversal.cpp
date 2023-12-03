

/*
Data Structures

Project:
A Data File Structure for a connected graph that produces a tree. There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is joining a node to itself (self-loop) or one of its ancestor in the tree produced by Data File Structure.
To find the back edge to any of its ancestor keep a visited array and if there is a back edge to any visited node then there is a loop and return true.


*/


//setting up the basic tools needed to run the program
#include <iostream> //adds input/output stream library to the program
#include <list> //includes the list library
#include <vector> //includes the vectory library
using namespace std;


class Graph {// Graph class created
    int num_vertices;//creat number of vertices
    list<int> *adj;// Pointer to an array containing adjacency lists.
    bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack);// Recursive function to find if there is a cycle in the graph.


public:// public section
    Graph(int num_vertices);// Constructor
    void addEdge(int v, int w);// Function to add an edge to the graph.
    bool isCyclic();// (is Cycle() is a Function to find if there is a cycle in the graph.
};// End of Graph class


/*
Graph function is used to add an edge between two vertices in the graph. The parameters v and w represent the vertices that are being connected by the edge. The function adds vertex w to the adjacency list of vertex v, which effectively creates an edge between v and w in the graph.
*/
Graph::Graph(int num_vertices) {// Constructor for the Graph class/ takes in the num of vert as paramater.
    this->num_vertices = num_vertices;// This-> to assign the number of vertices to the num_vertices member variable.
    adj = new list<int>[num_vertices];// Create an array of lists to represent the adjacency list.
}// End of Graph constructor

void Graph::addEdge(int v, int w) { // Function to add an edge to the graph.
    adj[v].push_back(w);// adds a new element w to adj[v]'s list.
    cout << "Edge added: " << v << " -> " << w << endl;
}// End of addEdge function


/*
bool Graph method recursively visits each neighbor of the current vertex and checks if they have been visited before. If a neighbor has not been visited, it calls itself recursively with the neighbor as the new current vertex. If the neighbor is already part of the current recursion stack, it means there is a cycle in the graph. If a cycle is found, the method returns true. If no cycle is found after exploring all neighbors, it returns false.
  */
bool Graph::isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack) {// Recursive function to find if there is a cycle in the graph.
    if(!visited[v]) {// if the vertex has not been visited.
        visited[v] = true;// mark the vertex as visited.
        recStack[v] = true;// mark the vertex as part of the current recursion stack.
      cout << "Vertex " << v << " is being visited for the first time" << endl;

        for(int neighbour : adj[v]) {// for each neighbour of the vertex.
          cout << "Edge "<<v << " to -> " << neighbour << " is currently being traversed" << endl;
            if (!visited[neighbour] && isCyclicUtil(neighbour, visited, recStack))// if the neighbour has not been visited and the recursion stack contains the neighbour.
                return true;// return true if there is a cycle.
            else if (recStack[neighbour])// if the current neighbour of the vertex is already part of the current recursion stack.(its a back edge of graph potentally a cycle)
                cout << "Revisiting vertex " << neighbour << endl;
                cout << "Loop found: " << v << " to -> " << neighbour << endl; 
                return true;// return true if there is a cycle in graph
        }// End of for loop
    }// End of if statement  
    else {
      cout << "Revisiting vertex " << v << endl;
  }


    recStack[v] = false;//setting the value at index 'v' in the recStack array to false. marks the vertex as not part of the current recursion stack.

    return false;
}


/*
bool Graph::isCyclic() function checks if there is a cycle in the graph. It does this by starting from each vertex and performing a depth-first search to visit each neighbor of the current vertex. If it finds a neighbor that is already part of the current recursion stack, it means there is a cycle in the graph. If it finds a cycle, it returns true; if not, it returns false.
  */
bool Graph::isCyclic() {// (is Cycle() is a Function to find if there is a cycle in the graph.
    vector<bool> visited(num_vertices, false);// Creating a visited array of size num_vertices and initializing all elements to false.
    vector<bool> recStack(num_vertices, false);// Creating a recStack array of size num_vertices and initializing all elements to false.
 
    for(int i = 0; i < num_vertices; i++)// loops through each vertex in the graph.
        if (isCyclicUtil(i, visited, recStack))// if the current vertex has not been visited and the recursion stack contains the vertex.
            return true;// return TRUE if there is a cycle in the graph.

    return false;// return FALSE if there is no cycle in the graph.
}


int main() {
    Graph graph(5);// Creating a graph with 5 vertices.
  graph.addEdge(0, 1);// Adding an edge between vertex 0 and vertex 1.
  graph.addEdge(0, 2);
  graph.addEdge(0, 3);
  graph.addEdge(1, 0);
  graph.addEdge(1, 2);
  graph.addEdge(2, 0);
  graph.addEdge(2, 1);
  graph.addEdge(3, 0);
  graph.addEdge(3, 4);
  graph.addEdge(4, 3);

    if (graph.isCyclic())
        cout << "The graph has a cycle." << endl;
    else
        cout << "The graph has no cycle." << endl;

    return 0;
}//end main
