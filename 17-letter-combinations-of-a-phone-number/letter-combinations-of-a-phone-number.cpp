class Solution {
public:
    vector<string> hash={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string cur = "";
    void dfs(string s, int t) {
        if (t == s.size()){
            res.push_back(cur);
            return;
        }

        auto c = s[t] - '0';
        for (auto cr : hash[c]){
            cur += cr;
            dfs(s, t+1);
            cur = cur.substr(0,cur.size()-1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        dfs(digits, 0);
        return res;
    }
};