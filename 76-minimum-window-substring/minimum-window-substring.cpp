class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int cnt = 0;                //s中有效字符数量
        int res = INT_MAX;
        string ans = "";
        unordered_map<char, int> hs, ht;
        for (auto c : t) ht[c]++;
        for (int i = 0, j = 0; i < s.size(); i++){
            hs[s[i]]++;
            if (hs[s[i]] <= ht[s[i]]){
                //说明刚刚加入了一个有效字符，
                cnt++;
            }

            while (j < i && hs[s[j]] > ht[s[j]]){
                hs[s[j]]--;
                j++;
            }

            if (cnt == t.size() && i-j+1 < res){
                res = i-j+1;
                ans = s.substr(j, res);
            }
        }
        return ans;
    }
};