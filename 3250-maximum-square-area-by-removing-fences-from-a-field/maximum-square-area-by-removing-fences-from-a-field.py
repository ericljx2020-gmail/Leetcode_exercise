class Solution:
    MOD = int(1e9 + 7)

    def maximizeSquareArea(self, m: int, n: int, hFences: list[int], vFences: list[int]) -> int:
        hFences.append(1)
        vFences.append(1)
        hFences.append(m)
        vFences.append(n)
        hash_map = {}
        res = 0
        
        for i in range(len(hFences)):
            for j in range(len(hFences)):
                if i == j:
                    continue
                diff = hFences[i] - hFences[j]
                if diff > 0:
                    hash_map[diff] = True
        
        for i in range(len(vFences)):
            for j in range(len(vFences)):
                if i == j:
                    continue
                diff = vFences[i] - vFences[j]
                if diff in hash_map:
                    res = max(res, diff)

        if res == 0:
            return -1
        return (res * res) % self.MOD

