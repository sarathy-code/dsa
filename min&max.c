#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition of the tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function prototypes
void findMinMax(TreeNode* node, int* min, int* max);
TreeNode* createNode(int value);

int main() {
    // Create a sample tree
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(1);
    root->left->right = createNode(8);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    // Variables to hold minimum and maximum values
    int min = INT_MAX;
    int max = INT_MIN;
    
    // Find minimum and maximum values
    findMinMax(root, &min, &max);
    
    // Print the results
    printf("Minimum value in the tree: %d\n", min);
    printf("Maximum value in the tree: %d\n", max);
    
    // Free allocated memory
    // (In practice, you should also free all nodes, but it's omitted here for brevity)
    
    return 0;
}

// Function to find the minimum and maximum values in the tree
void findMinMax(TreeNode* node, int* min, int* max) {
    if (node == NULL) {
        return;
    }
    
    // Update min and max based on the current node's value
    if (node->value < *min) {
        *min = node->value;
    }
    if (node->value > *max) {
        *max = node->value;
    }
    
    // Recursively find min and max in the left and right subtrees
    findMinMax(node->left, min, max);
    findMinMax(node->right, min, max);
}

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
