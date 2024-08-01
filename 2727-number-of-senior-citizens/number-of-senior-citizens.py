class Solution:
    def countSeniors(self, details: List[str]) -> int:
        ans = 0
        for p in details:
            age = int(p[-4:-2])
            if age > 60: ans += 1
        return ans
            