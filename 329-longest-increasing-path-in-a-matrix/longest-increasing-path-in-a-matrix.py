class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        m = len(matrix[0])
        dx = [0,0,-1,1]
        dy = [1,-1,0,0]
        res = 0
        
        @cache
        def dfs(x, y):
            res = 0
            for i in range(4):
                a = x + dx[i]
                b = y + dy[i]
                if a < 0 or a >= n or b < 0 or b >= m: continue
                if matrix[a][b] <= matrix[x][y]: continue
                res = max(res, dfs(a,b))

            res+=1
            return res

        for i in range(n):
            for j in range(m):
                res = max(res, dfs(i,j))
        
        return res