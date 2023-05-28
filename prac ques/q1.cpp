#include <iostream>
#include <climits>

#define V 5 // number of vertices in the graph

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V]; // the output array, dist[i] will hold the shortest distance from src to i
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    // initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // distance of source vertex from itself is always 0
    dist[src] = 0;

    // find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        // mark the picked vertex as processed
        sptSet[u] = true;

        // update dist value of adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print the constructed distance array
    std::cout << "Vertex\tDistance from Source" << std::endl;
    for (int i = 0; i < V; i++) {
        std::cout << i << "\t" << dist[i] << std::endl;
    }
}

int main() {
    int graph[V][V] = {{0, 4, 0, 0, 8},
                       {4, 0, 8, 0, 0},
                       {0, 8, 0, 7, 0},
                       {0, 0, 7, 0, 9},
                       {8, 0, 0, 9, 0}};

    dijkstra(graph, 0);

    return 0;
}
