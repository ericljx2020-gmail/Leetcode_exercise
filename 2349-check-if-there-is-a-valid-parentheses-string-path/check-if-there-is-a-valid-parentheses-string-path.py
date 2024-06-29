class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        n,m = len(grid), len(grid[0])
        if (m+n) % 2 == 0 or grid[0][0] == ')' or grid[n-1][m-1] == '(': return False

        @cache
        def dfs(x, y, c):
            #c表示未被匹配的(数量
            if c > m-x+n-y-1: return False          #说明后面就算全是)都匹配不完
            if x == n-1 and y == m-1: return c == 1    #最后一定是)
            c += 1 if grid[x][y] == '(' else -1
            return c >= 0 and (x < n-1 and dfs(x+1,y,c) or y < m-1 and dfs(x,y+1,c))

        return dfs(0,0,0)