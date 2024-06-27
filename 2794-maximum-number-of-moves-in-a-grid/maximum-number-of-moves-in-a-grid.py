class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        n,m = len(grid), len(grid[0])
        res = 0
        f = [[-1 for _ in range(m)] for _ in range(n)]
        for i in range(n):
            f[i][0] = 0
        for j in range(1, m):
            for i in range(n):
                if i-1 >= 0 and grid[i-1][j-1] < grid[i][j] and f[i-1][j-1] != -1:
                    f[i][j] = max(f[i][j], f[i-1][j-1]+1)
                if f[i][j-1] != -1 and grid[i][j-1] < grid[i][j]: f[i][j] = max(f[i][j], f[i][j-1]+1)
                if i+1 < n and grid[i+1][j-1] < grid[i][j] and f[i+1][j-1] != -1:
                    f[i][j] = max(f[i][j], f[i+1][j-1]+1)
                res = max(res, f[i][j])
        for c in f:
            print(c)
        return res