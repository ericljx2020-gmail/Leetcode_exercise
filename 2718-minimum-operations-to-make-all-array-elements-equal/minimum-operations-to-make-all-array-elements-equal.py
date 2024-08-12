from typing import List

class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        res = []
        nums.sort()
        n = len(nums)
        f = [0] * (n + 1)
        nums.insert(0, 0)
        
        for i in range(1, n + 1):
            f[i] = f[i - 1] + nums[i]
        
        for t in queries:
            p = self.find(t, nums, n)
            if p == n and nums[p] < t:
                res.append(t * n - f[n])
            elif p == 1 and nums[p] > t:
                res.append(f[n] - t * n)
            else:
                l = p * t - f[p]
                r = (f[n] - f[p]) - (n - p) * t
                res.append(l + r)
        
        return res

    def find(self, x: int, nums: List[int], n: int) -> int:
        l, r = 1, n
        while l < r:
            mid = (l + r + 1) // 2
            if nums[mid] <= x:
                l = mid
            else:
                r = mid - 1
        return r

