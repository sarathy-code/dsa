#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to perform pre-order traversal
void preorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    // Visit the root node
    printf("%d ", root->value);
    
    // Traverse the left subtree
    preorderTraversal(root->left);
    
    // Traverse the right subtree
    preorderTraversal(root->right);
}

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Create nodes
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform pre-order traversal
    printf("Pre-order Traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Free allocated memory (not shown here but recommended in a full implementation)

    return 0;
}
