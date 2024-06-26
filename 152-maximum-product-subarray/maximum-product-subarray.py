class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        g = [0 for _ in range(n+1)]
        f = [0 for _ in range(n+1)]
        g[0], f[0] = nums[0], nums[0]
        res = nums[0]
        for i in range(1, n):
            f[i] = max(nums[i], max(f[i-1] * nums[i], g[i-1] * nums[i]))
            g[i] = min(nums[i], min(f[i-1] * nums[i], g[i-1] * nums[i]))
            res = max(res, f[i])

        return res