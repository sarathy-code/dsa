#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function prototypes
int getHeight(TreeNode* node);
TreeNode* createNode(int value);

int main() {
    // Create a sample tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    // Calculate the height of the tree
    int height = getHeight(root);
    
    // Print the height
    printf("Height of the tree: %d\n", height);
    
    // Free allocated memory
    // (In practice, you should also free all nodes, but it's omitted here for brevity)
    
    return 0;
}

// Function to calculate the height of the tree
int getHeight(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    
    // Get the height of the left and right subtrees
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    
    // The height of the current node is the maximum of the heights of the left and right subtrees plus 1
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
