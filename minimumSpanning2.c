#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100000

// Structure to represent an edge
typedef struct {
    int u, v, weight, index;
} Edge;

// Union-Find data structure
int parent[MAX_EDGES], rank[MAX_EDGES];

// Function to initialize the Union-Find data structure
void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find function with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Union function with union by rank
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Function to calculate the MST weight using Kruskal's algorithm
int kruskal(int n, Edge* edges, int m, int excludeIndex, int includeIndex) {
    init(n);

    int mstWeight = 0;
    int edgesUsed = 0;

    // Force the inclusion of the specified edge if includeIndex is valid
    if (includeIndex != -1) {
        unionSets(edges[includeIndex].u, edges[includeIndex].v);
        mstWeight += edges[includeIndex].weight;
        edgesUsed++;
    }

    // Process the edges, skipping the edge at excludeIndex
    for (int i = 0; i < m; i++) {
        if (i == excludeIndex) continue;
        if (find(edges[i].u) != find(edges[i].v)) {
            unionSets(edges[i].u, edges[i].v);
            mstWeight += edges[i].weight;
            edgesUsed++;
        }
    }

    // If we've used exactly n-1 edges, it's a valid MST
    return (edgesUsed == n - 1) ? mstWeight : -1;
}

// Function to find the minimum spanning tree and determine critical and pseudo-critical edges
void findCriticalAndPseudoCriticalEdges(int n, Edge* edges, int m) {
    // Sort edges by weight
    qsort(edges, m, sizeof(Edge), [](const void* a, const void* b) {
        return ((Edge*)a)->weight - ((Edge*)b)->weight;
    });

    // Calculate the weight of the MST without removing any edges
    int mstWeight = kruskal(n, edges, m, -1, -1);

    for (int i = 0; i < m; i++) {
        // Check if edge[i] is critical by excluding it
        int weightWithoutEdge = kruskal(n, edges, m, i, -1);
        if (weightWithoutEdge == -1 || weightWithoutEdge > mstWeight) {
            printf("Edge %d is critical\n", edges[i].index);
        }

        // Check if edge[i] is pseudo-critical by including it
        int weightWithEdge = kruskal(n, edges, m, -1, i);
        if (weightWithEdge == mstWeight) {
            printf("Edge %d is pseudo-critical\n", edges[i].index);
        }
    }
}

int main() {
    int n = 5;
    Edge edges[] = {
        {0, 1, 1, 0},
        {1, 2, 2, 1},
        {0, 2, 3, 2},
        {1, 3, 4, 3},
        {3, 4, 5, 4},
        {2, 4, 6, 5}
    };
    int m = sizeof(edges) / sizeof(edges[0]);

    findCriticalAndPseudoCriticalEdges(n, edges, m);

    return 0;
}
