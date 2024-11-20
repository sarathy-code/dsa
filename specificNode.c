#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of a TreeNode
typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Function to search for a value in the BST
bool searchBST(TreeNode* root, int value) {
    if (root == NULL) {
        return false; // Value not found
    }

    if (root->value == value) {
        return true; // Value found
    }

    if (value < root->value) {
        return searchBST(root->left, value); // Search in left subtree
    } else {
        return searchBST(root->right, value); // Search in right subtree
    }
}

int main() {
    TreeNode* root = NULL;
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(values) / sizeof(values[0]);

    // Insert nodes into the binary tree
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    int searchValue = 4;
    if (searchBST(root, searchValue)) {
        printf("Value %d found in the BST.\n", searchValue);
    } else {
        printf("Value %d not found in the BST.\n", searchValue);
    }

    return 0;
}
