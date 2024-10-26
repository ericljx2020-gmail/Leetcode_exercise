class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        for (auto c : s) {
            if (c <= 'Z' && c >= 'A') {
                ss += 'a' + c - 'A';
            }else if ((c <= 'z' && c >= 'a') || (c <= '9' && c >= '0')){
                ss += c;
            }
        }
        for (int i = 0; i < ss.size() / 2; i++){
            if (ss[i] != ss[ss.size()-1-i]) return false;
        }
        return true;
    }
};