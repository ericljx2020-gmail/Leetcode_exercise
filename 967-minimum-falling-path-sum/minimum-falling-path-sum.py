class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        m = len(matrix[0])
        f = [[0 for _ in range(m)] for _ in range(n)]
        res = 0x3f3f3f3f
        for i in range(m):
            f[0][i] = matrix[0][i]
            if 0 == n-1: res = min(res, f[0][i])
        for i in range(1, n):
            for j in range(m):
                if j == 0: 
                    f[i][j] = min(f[i-1][j], f[i-1][j+1]) + matrix[i][j]
                    if i == n-1:
                        res = min(res, f[i][j])
                    continue
                if j == m-1: 
                    f[i][j] = min(f[i-1][j], f[i-1][j-1]) + matrix[i][j]
                    if i == n-1:
                        res = min(res, f[i][j])
                    continue
                f[i][j] = min(f[i-1][j-1], f[i-1][j+1], f[i-1][j]) + matrix[i][j]
                if i == n-1:
                    res = min(res, f[i][j])
        return res