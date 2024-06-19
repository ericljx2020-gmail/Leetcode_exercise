class Solution:
    def check(self, t: int, a: List[int], k: int, m: int) -> bool:
        #超过t的不看，每一个区间为k能否有m个
        cnt = 0
        j = 0
        for i in range(len(a)):
            if a[i] > t:
                j = i + 1
                continue
            if i - j + 1 == k:
                cnt += 1
                j = i + 1
        return cnt >= m
        
    def minDays(self, a: List[int], m: int, k: int) -> int:
        if len(a) // k < m:
            return -1
        l = 0
        r = max(a)
        while l < r:
            t = (l + r) // 2
            if self.check(t, a, k, m):
                r = t
            else:
                l = t + 1
        return l  # or return r, both are same when the loop ends
