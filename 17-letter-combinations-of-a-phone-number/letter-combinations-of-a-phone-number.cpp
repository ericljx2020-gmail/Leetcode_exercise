class Solution {
public:

    vector<string> res;
    vector<string> d = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string t = "";
    void dfs(int x, string digits) {
        if (x >= digits.size()) {
            res.push_back(t);
            return;
        }
        int dig = digits[x] - '0';
        for (int i = 0; i < d[dig].size(); i++){
            t += d[dig][i];
            dfs(x+1, digits);
            t = t.substr(0, t.size()-1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        dfs(0, digits);
        return res;
    }
};