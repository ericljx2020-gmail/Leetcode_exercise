class Solution:
    def maximumRemovals(self, s: str, p: str, removable: list[int]) -> int:
        m = len(removable)
        l, r = 0, m
        while l < r:
            mid = (l + r + 1) // 2
            if self.check(mid, s, p, removable):
                l = mid
            else:
                r = mid - 1
        return r

    def check(self, k: int, s: str, p: str, removable: list[int]) -> bool:
        hash_map = defaultdict(bool)
        for i in range(k):
            hash_map[removable[i]] = True
        j = 0
        for i in range(len(s)):
            if not hash_map[i] and s[i] == p[j]:
                j += 1
                if j == len(p):
                    return True
        return False

