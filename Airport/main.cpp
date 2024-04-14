#include <iostream>
#include <vector>
using namespace std;
#include <limits.h>

// Number of vertices in the graph
#define V 6

int minDistance(int dist[], bool sptSet[])
{

	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
	string airport[6] = {
		"Kansas City International Airport ", 
		"Charles B Wheeler Downtown Airport", 
		"Lee Summit Municipal Airport      ",
		"Johnson County Executive Airport  ",
		"Lawrence Regional Airport         ",
		"Rosecrans Memorial Airport        "};
	cout << "\nAirport Names \t\t\t\t Shortest distance from chosen airport (miles)" << endl << endl;
	for (int i = 0; i < V; i++)
		cout << airport[i] << "\t\t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's method
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; 
	bool sptSet[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist);
}


int main()
{

	int graph[V][V] = { { 0, 14, 30, 27, 33, 35},
						{ 14, 0, 0, 0, 0, 49},
						{ 30, 34, 0, 20, 0, 63},
						{ 27, 16, 20, 0, 0, 0},
						{ 33, 0, 0, 26, 0, 0},
						{ 35, 0, 0, 57, 58, 0}};

	// Function call
	int input;
	cout << "Please choose your starting airport:" << endl;
	cout << "0- Kansas City International Airport\n"
		<< "1- Charles B Wheeler Downtown Airport\n"
		<< "2- Lee Summit Municipal Airport\n"
		<< "3- Johnson County Executive Airport\n"
		<< "4- Lawrence Regional Airport\n"
		<< "5- Rosecrans Memorial Airport\n\n";

	cin >> input;

	dijkstra(graph, input);

	return 0;
}
