#include <iostream>
#include <vector>
#include <queue>
#include <climits>  // For INT_MAX

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {
        val = 0;
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// DFS Solution
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;  // The tree is empty
        }

        int max_child_depth = 0;
        for (Node* child : root->children) {
            int child_depth = maxDepth(child);  // Recursive call
            if (child_depth > max_child_depth) {
                max_child_depth = child_depth;
            }
        }
        return max_child_depth + 1;  // Add 1 to include the current node
    }
};

/*
// BFS Solution
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;  // The tree is empty
        }

        int depth = 0;
        std::queue<Node*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int level_size = queue.size();
            depth++;  // Increment depth at each level
            for (int i = 0; i < level_size; ++i) {
                Node* node = queue.front();
                queue.pop();
                for (Node* child : node->children) {
                    if (child) {
                        queue.push(child);
                    }
                }
            }
        }
        return depth;
    }
};
*/

// Function to build the tree from a vector representation
Node* build_tree(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }

    Node* root = new Node(values[0]);
    std::queue<Node*> node_queue;
    node_queue.push(root);

    size_t i = 2;  // Start from index 2 because index 1 is a separator (-1)
    while (!node_queue.empty() && i < values.size()) {
        Node* parent = node_queue.front();
        node_queue.pop();

        std::vector<Node*> children;
        while (i < values.size() && values[i] != INT_MIN) {
            Node* child = new Node(values[i]);
            children.push_back(child);
            node_queue.push(child);
            ++i;
        }
        parent->children = children;
        ++i;  // Skip the separator (INT_MIN)
    }
    return root;
}

// Helper function to replace None with INT_MIN for separators
std::vector<int> parse_values(const std::vector<int>& input_values) {
    std::vector<int> values;
    for (int val : input_values) {
        if (val == -1) {  // Assuming -1 represents None in the input
            values.push_back(INT_MIN);  // Use INT_MIN as a separator
        } else {
            values.push_back(val);
        }
    }
    return values;
}

// Testing the code with the examples
int main() {
    // Example 1
    std::vector<int> input_values1 = {1, -1, 3, 2, 4, -1, 5, 6};
    std::vector<int> values1 = parse_values(input_values1);
    Node* root1 = build_tree(values1);
    Solution solution;
    int depth1 = solution.maxDepth(root1);
    std::cout << "Maximum Depth (Example 1): " << depth1 << std::endl;  // Expected Output: 3

    // Cleanup
    // (Implement a function to delete the tree nodes to prevent memory leaks if necessary)

    // Example 2
    std::vector<int> input_values2 = {
        1, -1, 2, 3, 4, 5, -1, -1, 6, 7, -1, 8, -1, 9, 10,
        -1, -1, 11, -1, 12, -1, 13, -1, -1, 14
    };
    std::vector<int> values2 = parse_values(input_values2);
    Node* root2 = build_tree(values2);
    int depth2 = solution.maxDepth(root2);
    std::cout << "Maximum Depth (Example 2): " << depth2 << std::endl;  // Expected Output: 5

    // Cleanup
    // (Implement a function to delete the tree nodes to prevent memory leaks if necessary)

    return 0;
}