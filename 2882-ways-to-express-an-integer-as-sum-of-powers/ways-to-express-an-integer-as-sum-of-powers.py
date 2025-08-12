class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        f = [0 for _ in range(n+1)]
        f[0] = 1
        MOD = 1e9+7
        t = 0
        while pow(t+1,x) <= n:
            t += 1
        
        for i in range(1,t+1):
            d = pow(i,x)
            for j in range(n, d-1, -1):
                f[j] = (f[j] + f[j-d]) % MOD;

        return int(f[n])