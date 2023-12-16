class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int tt = -1, hh = 0;
        int q[1000005];
        int cur = 0;
        int res = 0;
        for (int i = 0; i < n; i++){
            if (hh <= i-k){
                if (s[q[hh]] == 'a' || s[q[hh]] == 'e' || s[q[hh]] == 'i' || s[q[hh]] == 'o' || s[q[hh]] == 'u'){
                    cur --;
                }
                hh++;
            }

            q[++tt] = i;
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                cur++;
            }
            res = max(cur, res);
        }
        return res;
    }
};