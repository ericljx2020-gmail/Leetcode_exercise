class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, int> hs, ht;
        for (auto c : t) ht[c]++;
        int res = INT_MAX;
        string ans = "";
        int cnt = 0;
        for (int i = 0, j = 0; i < n; i++){
            hs[s[i]]++;
            if (hs[s[i]] <= ht[s[i]]){
                cnt++;
            }

            while (j < i && hs[s[j]] > ht[s[j]]){
                hs[s[j]]--;
                j++;
            }
            if (cnt == t.size() && i-j+1 < res){
                res = i-j+1;
                ans = s.substr(j, i-j+1);
            }
        }
        return ans;
    }
};