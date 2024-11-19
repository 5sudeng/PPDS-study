### DFS INORDER

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution1:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.count = 0
        self.result = None
        self.inorderHelp(root, k)

        return self.result
        

    def inorderHelp(self, curNode, k) -> int :

        if not curNode or self.result is not None:
            return
        
        self.inorderHelp(curNode.left, k)
        self.count +=1 

        if self.count == k :
            self.result = curNode.val
        
        self.inorderHelp(curNode.right, k)



### Using Stack

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution2:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = []
        curr = root

        while stack or curr:
            while curr:
                stack.append(curr)
                curr = curr.left ## 왼쪽으로 끝까지 내려갔다가
            curr = stack.pop() ## pop을 하면서 
            k -= 1
            if k == 0: return curr.val ## k번째 작은 것 return
            curr = curr.right ## right가 있으면 right로 내려감