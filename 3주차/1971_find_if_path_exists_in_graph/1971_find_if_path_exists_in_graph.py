from collections import deque

class Solution:
    def validPath(self, n, edges, source, destination):
        neighbor = {i: [] for i in range(n)}
        for u, v in edges:
            neighbor[u].append(v)
            neighbor[v].append(u)
        
        visited = set()
        queue = deque([source])
        
        while queue:
            curr = queue.popleft()
            
            if curr == destination:
                return True
            
            if curr not in visited:
                visited.add(curr)
                for neighbor_node in neighbor[curr]:
                    if neighbor_node not in visited:
                        queue.append(neighbor_node)
        
        return False