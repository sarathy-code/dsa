#include <stdio.h>
#include <stdlib.h>

void topologicalSortUtil(int v, int visited[], int graph[5][5], int stack[]) {
    visited[v] = 1;
    for (int i = 0; i < 5; i++) {
        if (graph[v][i] == 1 && !visited[i])
            topologicalSortUtil(i, visited, graph, stack);
    }
    stack[v] = 1;
}

int main() {
    int graph[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    int visited[5] = {0};
    int stack[5] = {0};
    for (int i = 0; i < 5; i++) {
        if (!visited[i])
            topologicalSortUtil(i, visited, graph, stack);
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", stack[i]);
    }
    return 0;
}
