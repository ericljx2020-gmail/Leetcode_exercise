class Solution:
    def countBits(self, n: int) -> List[int]:
        res = []
        for i in range(n+1):
            cnt = 0
            for j in range(0, 32):
                cnt += (i >> j & 1)
            res.append(cnt)
        return res