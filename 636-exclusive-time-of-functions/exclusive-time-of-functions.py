class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        res = [0 for _ in range(n)]
        stk = []
        last = 0
        for log in logs:
            p = log.split(':')
            idx, op, t = int(p[0]), p[1], int(p[2])

            if op == "start":
                if len(stk):
                    res[stk[-1]] += t - last
                    last = t    
                stk.append(idx)
            else:
                res[stk[-1]] += t-last+1
                last = t+1
                stk.pop()
            
        return res