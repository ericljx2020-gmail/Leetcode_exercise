class Solution {
public:
    bool isSubsequence(string t, string s) {
        int idx = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == t[idx]){
                idx++;
            }
        }
        if (idx == t.size()) return true;
        return false;
    }
};