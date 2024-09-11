class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)
        self.flag = False
        def dfs(a, b, buffer):
            # global flag
            print(a,b)
            if (len(a) != 1 and a[0] == '0') or (len(b) != 1 and b[0] == '0'): return
            la = len(a)
            lb = len(b)
            a = int(a)
            b = int(b)
            c = str(a+b)
            if la+lb+len(c)+buffer > n: return
            if c == num[buffer+la+lb:buffer+la+lb+len(c)]:
                if buffer+la+lb+len(c) == n: 
                    self.flag = True
                    # print(self.flag)
                    return
                dfs(str(b), c, buffer+la)

        for i in range(1,n):
            for j in range(1,n):
                a = num[:i]
                b = num[i:i+j]
                dfs(a,b,0)
                # print(self.flag)
                if self.flag: return True

        return False