class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        l1 = Counter(s1.split(" "))
        l2 = Counter(s2.split(" "))
        ans = set()
        res = []
        for key, value in l1.items():
            if value == 1:
                if key not in l2:
                    if key not in ans: res.append(key)
                    ans.add(key)
        for key, value in l2.items():
            if value == 1:
                if key not in l1:
                    if key not in ans: res.append(key)
                    ans.add(key)
            
        return res