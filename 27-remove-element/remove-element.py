class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        # nums = sorted(nums)
        while nums.count(val):
            nums.remove(val)
        return len(nums)