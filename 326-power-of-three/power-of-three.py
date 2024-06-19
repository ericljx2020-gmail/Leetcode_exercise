class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n == 0: return False
        while n:
            if n != 1 and n % 3 != 0:
                return False
            n //= 3
            # print(n)
        return True