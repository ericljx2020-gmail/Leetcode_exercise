class Solution:
    def firstUniqChar(self, s: str) -> int:
        st = {}
        for c in s:
            if c not in st:
                st[c] = 1
            else:
                st[c] += 1
        for i,c in enumerate(s):
            if st[c] == 1:
                return i
        return -1