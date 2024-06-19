class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        for x in set(nums1):
            a = nums1.count(x)
            b = nums2.count(x)
            res += [x] * min(a,b)
        return res