class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        l = len(strs)
        @cache
        def dfs(i, m, n):
            if i >= l: return 0
            zeros = strs[i].count('0')
            ones = strs[i].count('1')
            if m >= zeros and n >= ones: return max(dfs(i+1, m-zeros, n-ones)+1, dfs(i+1, m, n));
            return dfs(i+1, m, n)
        return dfs(0,m,n)