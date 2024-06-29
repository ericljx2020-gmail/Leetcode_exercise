class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dx = [0,0,-1,1]
        dy = [1,-1,0,0]
        res = 0
        MOD = 1e9+7
        @cache
        def dfs(x,y):
            res = 0
            for i in range(4):
                a = x + dx[i]
                b = y + dy[i]
                if a < 0 or a >= n or b < 0 or b >= m: continue
                if grid[a][b] <= grid[x][y]: continue
                res += dfs(a,b)
            res += 1
            return res % MOD

        for i in range(n):
            for j in range(m):
                res = (res + dfs(i,j)) % MOD

        return int(res)