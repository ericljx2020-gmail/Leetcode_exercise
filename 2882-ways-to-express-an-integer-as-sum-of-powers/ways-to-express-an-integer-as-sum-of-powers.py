class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        MOD = 1e9+7
        powers = []
        b = 1
        while b < 400:
            a = pow(b, x)
            if a > n: break
            powers.append(a)
            b += 1

        f = [0 for _ in range(n+1)]
        f[0] = 1
        for power in powers:
            for i in range(n, -1, -1):
                if i >= power: f[i] =  (f[i] + f[i-power]) % MOD

        return int(f[n] % MOD)