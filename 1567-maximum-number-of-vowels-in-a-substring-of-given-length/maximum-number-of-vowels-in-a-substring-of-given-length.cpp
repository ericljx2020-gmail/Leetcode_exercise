class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char, bool> vow;
        int n = s.size();
        int q[100005];
        int tt = -1, hh = 0;
        vow['a'] = 1;
        vow['e'] = 1;
        vow['i'] = 1;
        vow['o'] = 1;
        vow['u'] = 1;
        
        int cnt = 0;
        int res = 0;
        for (int i = 0; i < n; i++){
            if (hh <= tt &&  q[hh] < i-k+1) {
                if (vow[s[q[hh]]]) cnt--;
                hh++;
            }
            if (vow[s[i]]) cnt++;
            q[++tt] = i;
            res = max(res, cnt);
        }

        return res;
    }
};