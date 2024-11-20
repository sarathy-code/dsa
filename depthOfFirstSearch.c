#include <stdio.h>
#include <stdbool.h>

#define V 6  // Number of vertices

void DFSUtil(int graph[V][V], int v, bool visited[]) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(int graph[V][V], int start) {
    bool visited[V] = {false};
    printf("Depth-First Search starting from vertex %d: ", start);
    DFSUtil(graph, start, visited);
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    DFS(graph, 0);  // Start DFS from vertex 0
    return 0;
}
