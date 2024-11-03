class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        int cnt = 0;

        for (auto c : t) ht[c]++;
        int ll = INT_MAX;
        string res = "";
        for (int i = 0, j = 0; i < s.size(); i++) {
            hs[s[i]]++;

            if (hs[s[i]] <= ht[s[i]]){
                cnt++;      //有效
            }

            while (j < i && hs[s[j]] > ht[s[j]]){
                hs[s[j]]--;
                j++;
            }
            if (cnt == t.size()) {
                if (i-j+1 < ll) {
                    ll = i-j+1;
                    res = s.substr(j, i-j+1);
                }
            }
        }
        return res;
    }
};