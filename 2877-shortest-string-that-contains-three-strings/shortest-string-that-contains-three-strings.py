class Solution:
    def __init__(self):
        self.perm = []
        self.orig = []
        self.cur = []
        self.st = {}

    def dfs(self, x: int) -> None:
        if x == 3:
            self.perm.append(self.cur[:])
            return

        for i in range(3):
            if i not in self.st or not self.st[i]:
                self.st[i] = True
                self.cur.append(self.orig[i])
                self.dfs(x + 1)
                self.cur.pop()
                self.st[i] = False

    def merge(self, a: str, b: str) -> str:
        if a in b: return b
        if b in a: return a

        for i in range(min(len(a), len(b)), 0, -1):
                # 枚举：s 的后 i 个字母和 t 的前 i 个字母是一样的
            if a[-i:] == b[:i]:
                return a + b[i:]
        return a + b


    def minimumString(self, a: str, b: str, c: str) -> str:
        self.orig = [a, b, c]
        self.orig.sort()
        self.dfs(0)
        res = ""
        print(self.perm)
        for e in self.perm:
            s = self.merge(e[0], self.merge(e[1], e[2]))
            print(s)
            if res == "" or len(s) < len(res) or (len(s) == len(res) and s < res):
                res = s
        return res

