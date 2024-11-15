# Definition for a binary tree node.


'''
return sum of all left leaves
left leaf : leaf that is the left child of another node (with no child)
- no children tree node
- 어떤 노드의 left child 이면서, children이 아무것도 없을 때.



Input: root = [3,9,20,null,null,15,7] : BFT ordering
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.


Example 2:

Input: root = [1] : root만 있을 경우는 leaf가 아님.
Output: 0

접근 방식
- 
'''



class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import Optional

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        

        ans = 0
        q = [root]
        
        while q:
            cur = q.pop(0)

            if cur.left is not None:
                

                temp = cur.left
                if (temp.left is None) and (temp.right is None): #left leaf
                    ans += temp.val
                
                
                else: # child가 있을 때 traversal할 이유가 있기에. leaf node는 필요없다.
                    q.append(cur.left)


            if cur.right is not None:
                q.append(cur.right)


        return ans



### 번외
def buils_tree(node_vals):
    if not node_vals:
        return None
    
    root =TreeNode(node_vals[0])
    q = [root]
    i  = 1 # indexing and counting

    while q and i<len(node_vals):
        node = q.pop(0)

        if node_vals[i] is not None:
            node.left = TreeNode(node_vals[i])
            q.append(node.left)
        i+=1

        if i<len(node_vals) and node_vals[i] is not None:
            node.right = TreeNode(node_vals[i])
            q.append(node.right)
        i+=1

    return root




def main():

    node_vals = [3,9, 20, None, None, 15, 7]

    root =buils_tree(node_vals)

    Sol = Solution()
    result = Sol.sumOfLeftLeaves(root)
    print("Ans : ", result)


if __name__ =="__main__":
    main()
