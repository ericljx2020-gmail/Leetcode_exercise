class Solution:
    def simplifyPath(self, path: str) -> str:
        ll = path.split('/')
        res = []
        for c in ll:
            if c == '' or c == '.':
                continue
            elif c == '..':
                if len(res): res.pop()
            else:
                res.append(c)
        # if len(res) == 0: return ""
        ans = "/"
        for i,c in enumerate(res):
            ans += c
            if i != len(res)-1: ans += '/'
        # ans = ans[:-1]
        return ans
