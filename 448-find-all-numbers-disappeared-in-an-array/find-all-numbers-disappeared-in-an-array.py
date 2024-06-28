class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        hash = set()
        for c in nums:
            hash.add(c)
            
        v = []
        for i in range(1, n+1):
            if i not in hash:
                v.append(i)
        return v