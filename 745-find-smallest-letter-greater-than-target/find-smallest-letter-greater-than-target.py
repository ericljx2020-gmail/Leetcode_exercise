class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if target < letters[0]: return letters[0]
        n = len(letters)
        l,r = 0, n-1
        while l < r:
            mid = l + r + 1 >> 1
            if letters[mid] <= target:
                l = mid
            else:
                r = mid-1
        return letters[r+1] if r+1 < n and letters[r+1] > target else letters[0]