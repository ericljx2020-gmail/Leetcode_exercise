class Solution:
    def maximumsSplicedArray(self, nums1: List[int], nums2: List[int]) -> int:
        #保证nums1大
        # print(sum(nums1), sum(nums2))
        if sum(nums1) < sum(nums2):
            nums1, nums2 = nums2, nums1
        # print(sum(nums1), sum(nums2))
        diff1 = []
        diff2 = []
        for i in range(len(nums1)):
            diff1.append(nums2[i] - nums1[i])
        for i in range(len(nums1)):
            diff2.append(nums1[i] - nums2[i])
        s1 = 0
        res1 = 0
        s2 = 0
        res2 = 0
        for i in range(len(diff1)):
            s1 = max(s1, 0) + diff1[i]
            res1 = max(res1, s1)
            s2 = max(s2, 0) + diff2[i]
            res2 = max(res2, s2)

        return max(sum(nums1)+res1, sum(nums2)+res2)