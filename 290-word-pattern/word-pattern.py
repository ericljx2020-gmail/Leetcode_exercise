class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        l = s.split(' ')
        if len(l) != len(pattern): return False
        mat1 = {}
        mat2 = {}
        for i in range(len(l)):
            if pattern[i] not in mat1 and l[i] not in mat2:
                mat1[pattern[i]] = l[i]
                mat2[l[i]] = pattern[i]
            elif pattern[i] in mat1 and l[i] != mat1[pattern[i]] or l[i] in mat2 and mat2[l[i]] != pattern[i]:
                return False
        return True