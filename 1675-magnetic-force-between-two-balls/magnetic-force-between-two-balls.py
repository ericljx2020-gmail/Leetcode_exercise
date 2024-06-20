class Solution:
    def maxDistance(self, p: List[int], m: int) -> int:
        l = 0
        r = max(p)
        p = sorted(p)
        while l < r:
            k = l + r + 1 >> 1
            if self.check(k, p, m):
                l = k
            else:
                r = k-1

        return r

    def check(self, k: int, p: List[int], m: int) -> bool:
        cur = p[0]
        m -= 1
        for i in range(1,len(p)):
            if p[i] - cur >= k:
                cur = p[i]
                m -= 1
                if m == 0: return True
        return False
                