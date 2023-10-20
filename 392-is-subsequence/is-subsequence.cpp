class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true; 
        int l = 0, r = 0;
        while (r < t.size()){
            if (t[r] == s[l]){
                l++;
                if (l == s.size()) return true;
            }
            r++;
        }
        return false;
    }
};