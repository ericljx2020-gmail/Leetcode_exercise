class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for (int i = 0; i <= 200; i++){
            if (strs[0].size() <= i) return res;
            char cur = strs[0][i];
            for (int j = 1; j < strs.size(); j++){
                if (strs[j][i] != cur) return res;
            }
            res += cur;
        }
        return res;
    }
};