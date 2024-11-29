class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        # DFS 함수 정의
        def dfs(node, curr_min, curr_max):
            if not node:
                # 리프 노드에 도달한 경우 최대 차이를 반환
                return curr_max - curr_min

            # 현재 노드 값으로 최소값과 최대값 업데이트
            curr_min = min(curr_min, node.val)
            curr_max = max(curr_max, node.val)

            # 왼쪽과 오른쪽 서브트리를 탐색
            left_diff = dfs(node.left, curr_min, curr_max)
            right_diff = dfs(node.right, curr_min, curr_max)

            # 왼쪽과 오른쪽 서브트리 중 더 큰 차이를 반환
            return max(left_diff, right_diff)

        # DFS 초기화: 루트의 값을 최소값과 최대값으로 설정
        return dfs(root, root.val, root.val)
