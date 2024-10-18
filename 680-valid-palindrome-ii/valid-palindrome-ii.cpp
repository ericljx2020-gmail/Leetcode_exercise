class Solution {
public:

    bool check(string s, int l, int r) {
        string ss = s.substr(l, r-l+1);
        int i = 0, j = ss.size()-1;
        while (i <= j){
            if (ss[i] != ss[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        while (i <= j) {
            if (s[i] != s[j]){
                return check(s, i, j-1) || check(s, i+1, j);
            }
            i++;
            j--;
        }
        return true;
    }
};