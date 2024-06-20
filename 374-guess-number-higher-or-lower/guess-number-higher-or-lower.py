# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        l = 0
        r = n
        while l < r:
            k = l + r + 1 >> 1
            if guess(k) == 1 or guess(k) == 0:
                l = k
            elif guess(k) == -1:
                r = k-1
        return r