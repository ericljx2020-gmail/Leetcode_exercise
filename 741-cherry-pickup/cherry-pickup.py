#思路在题解：https://leetcode.cn/problems/cherry-pickup/solutions/2766975/jiao-ni-yi-bu-bu-si-kao-dpcong-ji-yi-hua-ruue/
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        # t 表示走了t步
        # 第一个人坐标：[t-j, j]
        # 第二个人坐标：[t-k, k]
        # 由于是从 n-1, n-1开始遍历，每一个都有左边和上边推过来，所以不用判断>n的越界
        @cache
        def dfs(t, j, k):
            if j < 0 or k < 0 or t-j < 0 or t-k < 0 or grid[t-j][j] == -1 or grid[t-k][k] == -1: return -inf
            if t == 0:
                return grid[0][0]
            return max(dfs(t-1, j, k), dfs(t-1, j-1, k), dfs(t-1, j, k-1), dfs(t-1, j-1, k-1)) + grid[t-j][j] + (grid[t-k][k] if j != k else 0)
        
        n = len(grid)
        return max(dfs(n * 2 - 2, n-1, n-1), 0)
