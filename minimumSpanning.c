#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Helper function to calculate the Manhattan distance
int manhattanDistance(int* a, int* b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int totalCost = 0;
    int visited[pointsSize]; 
    int minDist[pointsSize]; 

    // Initialize visited and minDist arrays
    for (int i = 0; i < pointsSize; i++) {
        visited[i] = 0;
        minDist[i] = INT_MAX;
    }

    // Start with the first point
    minDist[0] = 0;

    for (int i = 0; i < pointsSize; i++) {
        int currMin = INT_MAX, currIndex = -1;

        // Find the unvisited node with the smallest distance
        for (int j = 0; j < pointsSize; j++) {
            if (!visited[j] && minDist[j] < currMin) {
                currMin = minDist[j];
                currIndex = j;
            }
        }

        // Add this point to the MST
        visited[currIndex] = 1;
        totalCost += currMin;

        // Update distances to the rest of the unvisited points
        for (int j = 0; j < pointsSize; j++) {
            if (!visited[j]) {
                int distance = manhattanDistance(points[currIndex], points[j]);
                if (distance < minDist[j]) {
                    minDist[j] = distance;
                }
            }
        }
    }

    return totalCost;
}

int main() {
    int pointsSize = 4;
    int pointsData[4][2] = {{0, 0}, {2, 2}, {3, 10}, {5, 2}};
    int* points[pointsSize];
    for (int i = 0; i < pointsSize; i++) {
        points[i] = pointsData[i];
    }
    int pointsColSize = 2;

    int result = minCostConnectPoints(points, pointsSize, &pointsColSize);
    printf("Minimum Cost to Connect All Points: %d\n", result);

    return 0;
}
