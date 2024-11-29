#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For INT_MIN

#define MAX_CHILDREN 100  // Adjust as necessary

// Definition for a Node.
typedef struct Node {
    int val;
    struct Node** children;
    int num_children;
} Node;

// Function to create a new node
Node* create_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->children = NULL;
    node->num_children = 0;
    return node;
}

// DFS Solution
int maxDepth(Node* root) {
    if (!root) {
        return 0;  // The tree is empty
    }

    int max_child_depth = 0;
    for (int i = 0; i < root->num_children; ++i) {
        int child_depth = maxDepth(root->children[i]);  // Recursive call
        if (child_depth > max_child_depth) {
            max_child_depth = child_depth;
        }
    }
    return max_child_depth + 1;  // Add 1 to include the current node
}

// Function to build the tree from an array representation
Node* build_tree(int* values, int size) {
    if (size == 0) {
        return NULL;
    }

    Node* root = create_node(values[0]);
    Node** node_queue = (Node**)malloc(size * sizeof(Node*));
    int front = 0, rear = 0;
    node_queue[rear++] = root;

    int i = 2;  // Start from index 2 because index 1 is a separator (INT_MIN)
    while (front < rear && i < size) {
        Node* parent = node_queue[front++];
        Node** children = (Node**)malloc(MAX_CHILDREN * sizeof(Node*));
        int child_count = 0;
        while (i < size && values[i] != INT_MIN) {
            Node* child = create_node(values[i]);
            children[child_count++] = child;
            node_queue[rear++] = child;
            ++i;
        }
        parent->children = children;
        parent->num_children = child_count;
        ++i;  // Skip the separator (INT_MIN)
    }

    free(node_queue);
    return root;
}

// Helper function to replace -1 with INT_MIN for separators
int* parse_values(int* input_values, int size) {
    int* values = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        if (input_values[i] == -1) {  // Assuming -1 represents None in the input
            values[i] = INT_MIN;  // Use INT_MIN as a separator
        } else {
            values[i] = input_values[i];
        }
    }
    return values;
}

// Function to free the tree nodes
void free_tree(Node* root) {
    if (!root) {
        return;
    }
    for (int i = 0; i < root->num_children; ++i) {
        free_tree(root->children[i]);
    }
    free(root->children);
    free(root);
}

// Testing the code with the examples
int main() {
    // Example 1
    int input_values1[] = {1, -1, 3, 2, 4, -1, 5, 6};
    int size1 = sizeof(input_values1) / sizeof(input_values1[0]);
    int* values1 = parse_values(input_values1, size1);
    Node* root1 = build_tree(values1, size1);
    int depth1 = maxDepth(root1);
    printf("Maximum Depth (Example 1): %d\n", depth1);  // Expected Output: 3

    // Cleanup
    free_tree(root1);
    free(values1);

    // Example 2
    int input_values2[] = {
        1, -1, 2, 3, 4, 5, -1, -1, 6, 7, -1, 8, -1, 9, 10,
        -1, -1, 11, -1, 12, -1, 13, -1, -1, 14
    };
    int size2 = sizeof(input_values2) / sizeof(input_values2[0]);
    int* values2 = parse_values(input_values2, size2);
    Node* root2 = build_tree(values2, size2);
    int depth2 = maxDepth(root2);
    printf("Maximum Depth (Example 2): %d\n", depth2);  // Expected Output: 5

    // Cleanup
    free_tree(root2);
    free(values2);

    return 0;
}