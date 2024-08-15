class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        cgs = {5:0, 10:0, 20:0}
        for b in bills:
            cgs[b] += 1
            ret = b - 5
            while ret >= 10 and cgs[10]:
                ret -= 10
                cgs[10] -= 1

            while ret > 0 and cgs[5]:
                ret -= 5
                cgs[5] -= 1
            
            if ret > 0: return False
        return True