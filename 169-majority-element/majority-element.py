class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        s = list(set(nums))
        freq = [(i, nums.count(i)) for i in s]
        return max(freq, key=lambda x: x[1])[0]