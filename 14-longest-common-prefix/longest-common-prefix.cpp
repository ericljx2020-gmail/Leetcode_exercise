class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string f = strs[0], e = strs[n-1];
        for (int i = 0; i < min(f.size(), e.size()); i++){
            if (f[i] != e[i]) return f.substr(0,i);
        }
        return strs[0];
    }
};