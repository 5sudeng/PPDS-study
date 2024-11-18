'''
Graph DFS, BFS

undirected graph, gvien adjacency list
- no self edges
- no parallel edges
- If v is in graph[u], then u is in graph[v]
- The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.: 꼭 반드시 연결되어 있지는 않는다는 듯.

Bipartite graph
- if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
- 노드들을 두개의 그룹으로 나눌 수 있으되, 같은 그룹의 노드끼리는 edge로 이어지지 않은 경우
- 참고로 edge가 아예 없고, 오로지 노드로만 이루어져도 biapartite graph

examles
graph = [[1,2,3],[0,2],[0,1,3],[0,2]] # False

graph = [[1,3],[0,2],[1,3],[0,2]] #True



strategy
- 임의의 노드 A, 다른 인접 노드 모두 B
- 이미 그룹이 할당된 노드가 현재 할당하려는 그룹과 다르면 Bipartite 그래프가 아님 (즉, 인접 노드가 같은 그룹이 되어야 하는 상황일 때 False)
'''




from typing import List

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        
        group_record = {}


        #모든 노드 순회하면서 해당 노드의 그룹 상태를 체크
        nums = len(graph)
        for node in range(nums):
            if node not in group_record: #방문을 하지 않았다면.

                if not self.BFS_check(node,graph, group_record ):
                # if not self.DFS_check(node, graph, group_record):
                    return False

        return True
    
    def BFS_check(self,start, graph, group_record):
        #인접 노드가 group record에 이미 있는데 같은 group을 할당하려고 할 때, 모순 발생


        #BFS : 이어진 것만
        
        q = [start] 
        group_record[start] = 0
        while q:
            v = q.pop(0) # left out
            current_group = group_record[v]

            #모든 인접노드에 대해
            for w in graph[v] : #모든 인접 행렬 
                if w not in group_record:
                    q.append(w)
                    group_record[w] = 1-current_group #다른 그룹 설정
        
                elif group_record[w] == current_group : # 이미 있고, 현재(부모노드)와 같은 group이라면?
                    return False
        
        return True
    

    def DFS_check(self, start, graph, group): #using stack
        
        stack = [start]
        group[start] = 0

        while stack :
            v = stack.pop()
            current_group = group[v]

            for w in reversed(graph[v]):
                if w not in group:
                    stack.append(w)
                    group[w] = 1- current_group
                elif group[w] == current_group:
                    return False
        return True
        


def main():
    graph = [[1,3],[0,2],[1,3],[0,2]]
    graph2 = [[1,2,3],[0,2],[0,1,3],[0,2]]

    sol = Solution()
    

    print(sol.isBipartite(graph))
    print(sol.isBipartite(graph2))

if __name__ == "__main__":
    main()