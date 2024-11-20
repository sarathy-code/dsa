#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int value;                // Value stored in the node
    struct TreeNode *left;    // Pointer to the left child
    struct TreeNode *right;   // Pointer to the right child
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to print tree nodes in-order (left, root, right)
void printInOrder(TreeNode* node) {
    if (node != NULL) {
        printInOrder(node->left);
        printf("%d\n", node->value);
        printInOrder(node->right);
    }
}

// Main function to demonstrate the tree node structure
int main() {
    // Create nodes
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    
    // Add more nodes
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(18);
    
    // Print the tree nodes
    printf("In-order traversal of the binary tree:\n");
    printInOrder(root);

    // Free allocated memory (not shown here for simplicity)
    // You would need to write a function to free all nodes in a real program

    return 0;
}
