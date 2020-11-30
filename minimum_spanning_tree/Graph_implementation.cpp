/*
 * Author : Varad Mashalkar
 * Lab : Data Structures and Algorithms.
 * Version 1
 * Date : 30-11-2020
 * File Description : File contains implementation for Graph data structures.
 * (Graph implemented using adjacency matrix)
 */

#include <iostream>
#include "Graph.h"
using namespace std;

Graph::Graph()
{
	/*
	 * Constructor
	 */
	vertices = 20;
	edges = 20;
	for (int i = 0; i < vertices; i++)
		for (int j = 0; j < vertices; j++)
			this->adjacencyMatrix[i][j] = 0;
}

void Graph::createGraph()
{
	/*
	 * Input : None
	 * Utility : Create graph by adding weights to adjacency matrix.
	 * Output : Adjacency Matrix
	 */
	cout<<"Enter number of vertices : "<<endl;
	cin>>this->vertices;
	while(this->vertices < 0 || this->vertices > 20)
	{
		cout<<"Vertices cannot be negative or greater than 20 !"<<endl;
		cout<<"Please re Enter number of vertices : ";
		cin>>this->vertices;
	}
	cout<<"Enter Number of edges : "<<endl;
	cin>>this->edges;
	while(this->edges < 0 || this->edges > (this->vertices * this->vertices))
	{
		cout<<"Vertices cannot be negative or greater than"<<(this->vertices * this->vertices)<<" !"<<endl;
		cout<<"Please re Enter number of vertices : ";
		cin>>this->edges;
	}
	for (int i = 0; i < this->vertices; i++)
	{
		this->paths[i] = 0;
		this->distances[i] = 5000;
	}
	int i = 0;
	while (i < this->edges)
	{
		cout<<"\nEdge "<<(i+1)<<endl;
		int v1, v2, w;
		cout<<"Vertex 1 : ";
		cin>>v1;
		while (v1 > this->vertices || v1 < 0)
		{
			cout<<"\nVertex cannot be greater than "<<this->vertices - 1<<" or negative!"<<endl;
			cout<<"Please re enter Vertex 1 : ";
			cin>>v1;
		}
		cout<<"\nVertex 2 : ";
		cin>>v2;
		while (v2 > this->vertices || v2 < 0)
		{
			cout<<"\nVertex cannot be greater than "<<this->vertices - 1<<" or negative!"<<endl;
			cout<<"Please re enter Vertex 2 : ";
			cin>>v2;
		}
		if (this->adjacencyMatrix[v1][v2] != 0 || this->adjacencyMatrix[v1][v2] != 0)
		{
			cout << "Edge with weight "<<this->adjacencyMatrix[v1][v2]<<" exists!"<<endl;
			continue;
		}
		if (v1 == v2)
		{
			cout<<"Loops not permitted !"<<endl;
			continue;
		}
		cout<<"Enter weight : ";
		cin>>w;
		while(w <= 0)
		{
			cout<<"Weight of edge cannot be negative or zero !"<<endl;
			cout<<"Please re Enter weight : ";
			cin>>w;
		}
		this->adjacencyMatrix[v1][v2] = w;
		this->adjacencyMatrix[v2][v1] = w;
		this->edge[i].vertex_1 = v1;
		this->edge[i].vertex_2 = v2;
		this->edge[i].weight = w;
		i += 1;
	}
	cout<<"\nInsertion process complete !"<<endl;
	cout<<"Matrix is :"<<endl;
	cout<<endl;
	for (int i = 0; i<this->vertices; i++)
	{
		for (int j = 0; j<this->vertices; j++)
		{
			cout<<this->adjacencyMatrix[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void Graph::Prims_MST()
{
	/*
	 * Input : None
	 * Utility : Display Minimum Spanning tree for entered graph.
	 * Output : MST in tabular format.
	 */
	//if graph is empty, return to call.
	if (this->vertices == 0 || this->edges == 0)
	{
		cout<<"Graph Empty!"<<endl;
		return;
	}
	//set visited array to false.
	for (int i = 0; i < this->vertices; i++)
	{
		this->visited_array[i] = 0;
	}
	//visit first element in array.
	this->visited_array[0] = true;
	//tabular display.
	cout<<"Minimum Spanning Tree"<<endl;
	cout<<"Edge\t|Weight"<<endl;
	int minimum_cost = 0;
	int visited_edges = 0;
	while (visited_edges < (this->vertices - 1))
	{
		int min = 32767;
		int r = 0, c = 0;
		for (int i = 0; i<this->vertices; ++i)
		{
			if (visited_array[i])
			{
				for (int j = 0; j<this->vertices; ++j)
				{
					if (min > this->adjacencyMatrix[i][j])
					{
						if (this->adjacencyMatrix[i][j] && !this->visited_array[j])
						{
							min = this->adjacencyMatrix[i][j];
							r = i;
							c = j;
						}
					}
				}
			}
		}
		minimum_cost += this->adjacencyMatrix[r][c];
		cout<<" "<<r<<"->"<<c<<"\t|"<<this->adjacencyMatrix[r][c]<<endl;
		this->visited_array[c] = 1;
		visited_edges += 1;
	}
	cout<<"\nMinimum Cost : "<<minimum_cost;
}

void Graph::sort_graph()
{
	/*
	 * Input : None
	 * Utility : Sort edges according to weights in non decreaing order.
	 * Output : None.
	 */
	//Algorithm of bubble sort implemented.
	bool swapped = false;
	do
	{
		swapped = false;
		for (int i = 0; i < this->edges - 1; i++)
		{
			if (this->edge[i].weight > this->edge[i+1].weight)
			{
				Edge temp = this->edge[i];
				this->edge[i] = this->edge[i+1];
				this->edge[i+1] = temp;
				swapped = true;
			}
		}
	}while (swapped);

	cout<<"\nSorted list of edges : "<<endl;
	cout<<"Edge\t|Weight"<<endl;
	for (int i = 0; i < this->edges; i++)
		cout<<this->edge[i].vertex_1<<"->"<<this->edge[i].vertex_2<<"\t|"<<this->edge[i].weight<<endl;
}

void Graph::Kruskals_MST()
{
	/*
	 * Input : None
	 * Utility : Display Minimum Spanning tree for entered graph using Kruskal's Algorithm.
	 * Output : MST in tabular format.
	 */
	//If graph is empty, return to call.
	if (this->vertices == 0 || this->edges == 0)
	{
		cout<<"Graph Empty!"<<endl;
		return;
	}
	//else compute MST.
	cout<<"\nEdge array is :"<<endl;
	cout<<"Edge\t|Weight"<<endl;
	for (int i = 0; i < this->edges; i++)
		cout<<this->edge[i].vertex_1<<"->"<<this->edge[i].vertex_2<<"\t|"<<this->edge[i].weight<<endl;
	this->sort_graph();
	//set visited array to false.
	for (int i = 0; i < this->vertices; i++)
	{
		this->visited_array[i] = 0;
	}
	//implement loop.
	Edge output[this->edges - 1];
	int connection[10], k, r, p, val, count = 0;
	//set connection array to 0.
	for (int i = 0; i < this->edges - 1; i++)
		connection[i] = 0;

	val = 1;
	count = 0;
	int j = 0;
	while (count < this->vertices - 1 && j < this->edges)
	{
		//If both vertices are not visited, add edge to tree.
		if (connection[edge[j].vertex_1] == 0 && connection[edge[j].vertex_2] == 0)
		{
			output[count] = edge[j];
			connection[edge[j].vertex_1] = val;
			connection[edge[j].vertex_2] = val;
			val++;
			count++;
		}
		//if connection value of both vertices of current edge is unequal :
		else if (connection[edge[j].vertex_1] != connection[edge[j].vertex_2])
		{
			//if both vertices are visited
			if (connection[edge[j].vertex_1] != 0 && connection[edge[j].vertex_2]!=0)
			{
				//add edge to minimum spanning tree.
				output[count] = edge[j];
				//if connection value of vertex 1 is less than that of vertex 2, set r an p values accordingly.
				if (connection[edge[j].vertex_1] < connection[edge[j].vertex_2])
				{
					r = connection[edge[j].vertex_1];
					p = connection[edge[j].vertex_2];
				}
				//if connection value of vertex 1 is more than that of vertex 2, set r an p values accordingly.
				else
				{
					r = connection[edge[j].vertex_2];
					p = connection[edge[j].vertex_1];
				}
				//replace all connection values at higher value(p) with lower value(r).
				for (k = 0; k<this->edges; k++)
				{
					if (connection[k] == p)
						connection[k] = r;
				}
				count++;
			}
			//If 1 vertex is visited, add edge to MST and set connection value of non visited vertex to that of the visited vertex.
			else if (connection[edge[j].vertex_1] == 0 && connection[edge[j].vertex_2] != 0)
			{
				output[count] = edge[j];
				connection[edge[j].vertex_1] = connection[edge[j].vertex_2];
				count++;
			}
			else
			{
				output[count] = edge[j];
				connection[edge[j].vertex_2] = connection[edge[j].vertex_1];
				count++;
			}
		}
		//edge is rejected if both connection values (for vertex 1 and vertex 2 are same. The edge thus forms a cycle if added to MST).
		j++;
	}
	int cost = 0;
	//Display spanning tree.
	cout<<"\nMinimum Spanning Tree"<<endl;
	cout<<"Edge\t|Weight"<<endl;
	for (int i = 0; i<count; i++)
	{
		cout<<output[i].vertex_1<<"->"<<output[i].vertex_2<<"\t|"<<output[i].weight<<endl;
		cost += output[i].weight;
	}
	cout<<"Minimum Cost : "<<cost<<endl;
}
