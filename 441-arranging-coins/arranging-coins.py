class Solution:
    def arrangeCoins(self, n: int) -> int:
        l = 1
        r = n
        while l < r:
            k = l + r + 1 >> 1;
            if (1+k) * k // 2 <= n:
                l = k
            else:
                r = k-1
        return r