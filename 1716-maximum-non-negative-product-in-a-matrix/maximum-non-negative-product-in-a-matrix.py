class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        MOD = 1e9+7
        n, m = len(grid), len(grid[0])
        f = [[0] * (m + 1) for _ in range(n + 1)]
        g = [[0] * (m + 1) for _ in range(n + 1)]
        f[0][0] = g[0][0] = grid[0][0]
        for i in range(1, n):
            f[i][0] = max(f[i-1][0] * grid[i][0], g[i-1][0] * grid[i][0])
            g[i][0] = min(f[i-1][0] * grid[i][0], g[i-1][0] * grid[i][0])
        for j in range(1, m):
            f[0][j] = max(f[0][j-1] * grid[0][j], g[0][j-1] * grid[0][j])
            g[0][j] = min(f[0][j-1] * grid[0][j], g[0][j-1] * grid[0][j])

        for i in range(1, n):
            for j in range(1, m):
                f[i][j] = max(max(f[i-1][j] * grid[i][j], g[i-1][j] * grid[i][j]),
                              max(f[i][j-1] * grid[i][j], g[i][j-1] * grid[i][j]))
                g[i][j] = min(min(f[i-1][j] * grid[i][j], g[i-1][j] * grid[i][j]),
                              min(f[i][j-1] * grid[i][j], g[i][j-1] * grid[i][j]))

        if f[n-1][m-1] >= 0:
            return int(f[n-1][m-1] % MOD)
        return -1

