from collections import deque
from typing import List

class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        max_fish = 0
        m = len(grid)
        n = len(grid[0]) if m > 0 else 0
        visited = [[False for _ in range(n)] for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0 and not visited[i][j]:
                    # BFS to find all connected cells
                    queue = deque()
                    queue.append((i, j))
                    visited[i][j] = True
                    current_sum = grid[i][j]
                    
                    while queue:
                        r, c = queue.popleft()
                        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                            nr, nc = r + dr, c + dc
                            if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc] and grid[nr][nc] > 0:
                                visited[nr][nc] = True
                                current_sum += grid[nr][nc]
                                queue.append((nr, nc))
                                
                    max_fish = max(max_fish, current_sum)
        
        return max_fish