# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children  # List of child nodes


from collections import deque


## DFS
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0  # The tree is empty

        max_child_depth = 0
        for child in root.children:
            child_depth = self.maxDepth(child) # Recursive call
            if child_depth > max_child_depth:
                max_child_depth = child_depth
        return max_child_depth + 1  # Add 1 to include the current node

## BFS
# class Solution:
#     def maxDepth(self, root: 'Node') -> int:
#         if not root:
#             return 0  # The tree is empty
#
#         depth = 0
#         queue = deque([root])
#
#         while queue:
#             level_size = len(queue)
#             depth += 1  # Increment depth at each level
#             for _ in range(level_size):
#                 node = queue.popleft()
#                 if node.children:
#                     queue.extend(node.children)
#
#         return depth

def build_tree(values):
    if not values:
        return None

    root = Node(values[0], [])
    queue = deque([root])
    i = 2  # Start from index 2 because index 1 is None (separator)

    while queue and i < len(values):
        parent = queue.popleft()
        children = []
        while i < len(values) and values[i] is not None:
            child = Node(values[i], [])
            children.append(child)
            queue.append(child)
            i += 1
        parent.children = children
        i += 1  # Skip the None separator
    return root


# Testing the code with the examples
if __name__ == "__main__":
    # Example 1
    values1 = [1, None, 3, 2, 4, None, 5, 6]
    root1 = build_tree(values1)
    solution = Solution()
    depth1 = solution.maxDepth(root1)
    print(f"Maximum Depth (Example 1): {depth1}")  # Expected Output: 3

    # Example 2
    values2 = [1, None, 2, 3, 4, 5, None, None, 6, 7, None, 8, None, 9, 10,
               None, None, 11, None, 12, None, 13, None, None, 14]
    root2 = build_tree(values2)
    depth2 = solution.maxDepth(root2)
    print(f"Maximum Depth (Example 2): {depth2}")  # Expected Output: 5