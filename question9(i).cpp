// C++ program for the above algorithm

#include <bits/stdc++.h>
using namespace std;
#define V 5

// Function to find index of max-weight
// vertex from set of unvisited vertices
int findMaxVertex(bool visited[], int weights[])
{

	// Stores the index of max-weight vertex
	// from set of unvisited vertices
	int index = -1;

	// Stores the maximum weight from
	// the set of unvisited vertices
	int maxW = INT_MIN;

	// Iterate over all possible
	// nodes of a graph
	for (int i = 0; i < V; i++) {

		// If the current node is unvisited
		// and weight of current vertex is
		// greater than maxW
		if (visited[i] == false
			&& weights[i] > maxW) {

			// Update maxW
			maxW = weights[i];

			// Update index
			index = i;
		}
	}
	return index;
}

// Utility function to find the maximum
// spanning tree of graph
void printMaximumSpanningTree(int graph[V][V],
							int parent[])
{

	// Stores total weight of
	// maximum spanning tree
	// of a graph
	int MST = 0;

	// Iterate over all possible nodes
	// of a graph
	for (int i = 1; i < V; i++) {

		// Update MST
		MST += graph[i][parent[i]];
	}

	cout << "Weight of the maximum Spanning-tree "
		<< MST << '\n'
		<< '\n';

	cout << "Edges \tWeight\n";

	// Print the Edges and weight of
	// maximum spanning tree of a graph
	for (int i = 1; i < V; i++) {
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
	}
}

// Function to find the maximum spanning tree
void maximumSpanningTree(int graph[V][V])
{

	// visited[i]:Check if vertex i
	// is visited or not
	bool visited[V];

	// weights[i]: Stores maximum weight of
	// graph to connect an edge with i
	int weights[V];

	// parent[i]: Stores the parent node
	// of vertex i
	int parent[V];

	// Initialize weights as -INFINITE,
	// and visited of a node as false
	for (int i = 0; i < V; i++) {
		visited[i] = false;
		weights[i] = INT_MIN;
	}

	// Include 1st vertex in
	// maximum spanning tree
	weights[0] = INT_MAX;
	parent[0] = -1;

	// Search for other (V-1) vertices
	// and build a tree
	for (int i = 0; i < V - 1; i++) {

		// Stores index of max-weight vertex
		// from a set of unvisited vertex
		int maxVertexIndex
			= findMaxVertex(visited, weights);

		// Mark that vertex as visited
		visited[maxVertexIndex] = true;

		// Update adjacent vertices of
		// the current visited vertex
		for (int j = 0; j < V; j++) {

			// If there is an edge between j
			// and current visited vertex and
			// also j is unvisited vertex
			if (graph[j][maxVertexIndex] != 0
				&& visited[j] == false) {

				// If graph[v][x] is
				// greater than weight[v]
				if (graph[j][maxVertexIndex] > weights[j]) {

					// Update weights[j]
					weights[j] = graph[j][maxVertexIndex];

					// Update parent[j]
					parent[j] = maxVertexIndex;
				}
			}
		}
	}

	// Print maximum spanning tree
	printMaximumSpanningTree(graph, parent);
}

// Driver Code
int main()
{

	// Given graph
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	// Function call
	maximumSpanningTree(graph);

	return 0;
}
