class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = -1,l = 0;
        int n = s.size();
        int idx = n-1;
        while (idx >= 0){
            if (r != -1 && s[idx] == ' '){
                l = idx+1;
                break;
            }
            if (r == -1 && s[idx] != ' '){
                r = idx;
            }
            idx--;
        }
        return r-l+1;
    }
};