class Solution:
    def subStrHash(self, s: str, power: int, modulo: int, k: int, hashValue: int) -> str:
        n = len(s)
        q = [0] * 1000000
        tt, hh = -1, 0
        v = 0
        p = 1
        for i in range(n):
            if hh <= tt and q[hh] < i-k+1:
                c = ord(s[q[hh]]) - ord('a') + 1
                v -= c
                hh += 1
            q[tt+1] = i
            tt += 1
            if i <= k-1:
                v = (v + (ord(s[i]) - ord('a') + 1) * p)
                p *= power
                if i == k-1 and v % modulo == hashValue:
                    return s[:k]
            else:
                v = (v + (ord(s[i]) - ord('a') + 1) * p)
                v //= power
                if v % modulo == hashValue:
                    return s[i-k+1:i+1]
        return ""

