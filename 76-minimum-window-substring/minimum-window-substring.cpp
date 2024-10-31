class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        int cnt = 0;
        int res = INT_MAX;
        for (auto c : t) ht[c]++;
        string word = "";
        for (int i = 0, j = 0; i < s.size(); i++){
            hs[s[i]]++;
            if (hs[s[i]] <= ht[s[i]]){
                cnt++;
            }

            while (j < i && hs[s[j]] > ht[s[j]]){
                hs[s[j]]--;
                j++;
            }

            if (cnt == t.size()){
                if (i-j+1 < res){
                    res = i-j+1;
                    word = s.substr(j, res);
                }
            }
        }
        return word;
    }
};