class Solution:
    def distinctEchoSubstrings(self, s: str) -> int:
        n = len(s)
        ans = 0
        seen = set()
        for i in range(n):
            for j in range(i+1, n):
                if (j-i+1) % 2 != 0:
                    continue
                substr = s[i:j+1]
                if substr not in seen and substr[:len(substr)//2] == substr[len(substr)//2:]:
                    ans += 1
                    seen.add(substr)
        return ans

