class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        #f[i][j]: 从[i][j] 走到 [n-1][m-1] 最少需要多少健康值
        #f[i][j] = min(f[i+1][j], f[i][j+1]) - dungeon[i][j]
        n = len(dungeon)
        m = len(dungeon[0])
        f = [[0 for _ in range(m)] for _ in range(n)]
        f[n-1][m-1] = max(0, -dungeon[n-1][m-1])+1
        for i in range(n-2, -1, -1):
            f[i][m-1] = max(1, f[i+1][m-1] - dungeon[i][m-1])
        for j in range(m-2, -1, -1):
            f[n-1][j] = max(1, f[n-1][j+1] - dungeon[n-1][j])

        for i in range(n-2, -1, -1):
            for j in range(m-2, -1, -1):
                f[i][j] = max(1, min(f[i+1][j], f[i][j+1])) - dungeon[i][j]
        
        for i in range(n):
            print(f[i])
        if f[0][0] >= 1: return f[0][0]
        
        return 1