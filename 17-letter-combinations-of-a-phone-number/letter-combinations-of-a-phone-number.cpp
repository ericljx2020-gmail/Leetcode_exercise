class Solution {
public:
    vector<string> ans;
    vector<string> hash={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string cur = "";
    void dfs(string digits, int idx){
        if (idx == digits.size()){
            ans.push_back(cur);
            return;
        }
        char c = digits[idx];
        int p = c - '0';
        for (int i = 0; i < hash[p].size(); i++){
            cur += hash[p][i];
            dfs(digits, idx+1);
            cur = cur.substr(0,cur.size()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        dfs(digits, 0);
        return ans;
    }
};