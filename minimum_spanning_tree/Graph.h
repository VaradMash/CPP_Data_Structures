/*
 * Author : Varad Mashalkar
 * Lab : Data Structures and Algorithms.
 * Version 1
 * Date : 30-11-2020
 * File Description : File contains ADT for Graph data structures.
 * (Graph implemented using adjacency matrix)
 */

#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_
#define MAX 20

struct Edge
{
	/*
	 * Structure to store edge of graph.
	 */
	int vertex_1, vertex_2, weight;
};

class Graph
{
private:
	int adjacencyMatrix[MAX][MAX];
	int visited_array[MAX];
	int vertices, edges;
	Edge edge[MAX];
	int distances[MAX], paths[MAX];
public:
	Graph();				//Constructor
	void createGraph();		//Method to create graph.
	void Prims_MST();		//Method to determine Minimum spanning tree in graph using Prim's Algorithm.
	void Kruskals_MST();	//Method to determine Minimum Spanning tree in graph using Kruskal's Algorithm.
	void sort_graph();		//Method to sort edge array of graph for Kruskal's algorithm.
};





#endif /* SRC_GRAPH_H_ */
