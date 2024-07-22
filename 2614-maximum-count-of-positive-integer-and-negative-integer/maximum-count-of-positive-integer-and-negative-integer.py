class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        if nums[0] > 0: return len(nums)
        if nums[-1] < 0: return len(nums)
        t = 0
        l,r = 0, len(nums)-1
        while l < r:
            mid = l + r + 1 >> 1
            if nums[mid] <= t:
                l = mid
            else:
                r = mid-1
        rr = r+1

        l,r = 0, len(nums)-1
        while l < r:
            mid = l + r >> 1
            if nums[mid] >= t:
                r = mid
            else:
                l = mid+1
        ll = r-1
        neg = max(0, ll+1)
        pos = max(0, len(nums)-rr)
        return max(neg, pos)