class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        if len(num1) < len(num2):
            num1, num2 = num2, num1
        s = ''
        idx = 1
        add = 0
        while idx <= len(num2):
            c = int(num2[len(num2)-idx]) + int(num1[len(num1)-idx])
            s = str((c+add) % 10) + s
            add = (c+add) // 10
            idx += 1

        print(s)

        while idx <= len(num1):
            c = int(num1[len(num1)-idx])+add
            add = c // 10
            g = c % 10
            s = str(g) + s
            idx += 1
            

        while add:
            s = str(add) + s
            add = 0
        return s