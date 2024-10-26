class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int i = 0, j = strs.size()-1;
        int idx = 0;
        string res = "";
        while (idx < strs[i].size() && idx < strs[j].size()) {
            if (strs[i][idx] != strs[j][idx]) return res;
            else{
                res += strs[i][idx];
            }
            idx++;
        }
        return res;
    }
};