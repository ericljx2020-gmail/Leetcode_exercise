class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for (auto c : s) {
            if ('a' <= c && c <= 'z') t += c;
            else if ('A' <= c && c <= 'Z') t += (c+32);
            else if ('0' <= c && c <= '9') t += c;
            else continue;
        }
        for (int i = 0; i < t.size()/2; i++) {
            if (t[i] != t[t.size()-i-1]) return false;
        }
        return true;
    }
};