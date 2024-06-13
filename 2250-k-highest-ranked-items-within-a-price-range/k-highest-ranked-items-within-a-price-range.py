from collections import deque

class Solution:
    def highestRankedKItems(self, grid: List[List[int]], pricing: List[int], start: List[int], k: int) -> List[List[int]]:
        dx = [0, 0, -1, 1]
        dy = [1, -1, 0, 0]
        c, d = start
        res, ans = [], []
        q = deque([(0, (start[0], start[1]))])
        st = {}
        st[(start[0], start[1])] = 1
        if pricing[0] <= grid[start[0]][start[1]] <= pricing[1]:
            res.append([0, start[0], start[1]])
        
        while q:
            t = q.popleft()
            for i in range(4):
                a, b = t[1][0] + dx[i], t[1][1] + dy[i]
                if 0 <= a < len(grid) and 0 <= b < len(grid[0]) and grid[a][b] != 0 and (a, b) not in st:
                    st[(a, b)] = 1
                    if pricing[0] <= grid[a][b] <= pricing[1]:
                        res.append([t[0] + 1, a, b])
                    q.append((t[0] + 1, (a, b)))
        
        res.sort(key=lambda x: (x[0], grid[x[1]][x[2]], x[1], x[2]))
        for i in range(min(len(res), k)):
            ans.append([res[i][1], res[i][2]])
        
        return ans

