class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        if (s.size() == 0) return 0;
        int n = s.size();
        int cnt = 0;
        int res = 1;
        for (int i = 1, j = 0; i < n; i++){
            if (s[i] == s[i-1]){
                cnt++;
                if (cnt == 2){
                    while (j < i && cnt == 2){
                        if (s[j] == s[j+1]) cnt--;
                        j++;
                    }
                }
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};