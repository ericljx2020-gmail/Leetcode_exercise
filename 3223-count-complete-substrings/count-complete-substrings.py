class Solution:
    def countCompleteSubstrings(self, w: str, k: int) -> int:
        
        def calc(s):
            res = 0
            v = len(s)
            for i in range(1, 27):
                if i * k > v:
                    break
                l = i * k               # 窗口右端点
                cnt = Counter(s[:l])
                freq = Counter(cnt.values())

                if freq[k] == i: res += 1

                for idx in range(v - l):
                    freq[cnt[s[idx]]] -= 1  #出列的s[idx]的frequence出现次数--
                    cnt[s[idx]] -= 1        #计数减少
                    freq[cnt[s[idx]]] += 1  #新的计数++

                    freq[cnt[s[idx+l]]] -= 1 #右边进来的本来的freq减少
                    cnt[s[idx+l]] += 1       #计数增加
                    freq[cnt[s[idx+l]]] += 1 #freq++

                    if freq[k] == i: res += 1    
            return res


        idx = 0
        n = len(w)
        ans = 0
        for i in range(1, n):
            if abs(ord(w[i]) - ord(w[i-1])) > 2:
                ans += calc(w[idx:i])
                idx = i
        ans += calc(w[idx:])
        return ans