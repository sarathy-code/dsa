#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function prototypes
void postOrderTraversal(TreeNode* node);
TreeNode* createNode(int value);

int main() {
    // Create a sample tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    // Perform post-order traversal
    printf("Post-order traversal: ");
    postOrderTraversal(root);
    
    // Free allocated memory
    // (In practice, you should also free all nodes, but it's omitted here for brevity)
    
    return 0;
}

// Function to perform post-order traversal
void postOrderTraversal(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    
    // Traverse left subtree
    postOrderTraversal(node->left);
    
    // Traverse right subtree
    postOrderTraversal(node->right);
    
    // Process the current node
    printf("%d ", node->value);
}

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
