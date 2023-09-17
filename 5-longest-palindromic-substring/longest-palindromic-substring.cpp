class Solution {
public:
    static const int N = 1e3+5;
    string longestPalindrome(string s) {
        int f[N][N];
        memset(f, 0, sizeof f);
        int n = s.size();
        for (int i = 0; i < n; i++) f[i][i] = 1;        //长度为1的一定是palindrome
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]){
                f[i][i+1] = 1;    //长度为2的一定是palindrome
            }
        }

        for (int l = 3; l <= n; l++){
            for (int i = 0; i < n; i++){
                int j = i + l - 1;
                if (j >= s.size()) break;
                if (s[i] == s[j] && f[i+1][j-1]) f[i][j] = 1;
            }
        }
        int maxlen = 0;
        string res = "";
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if (f[i][j]){
                    if (j-i+1 > maxlen){
                        maxlen = j-i+1;
                        res = s.substr(i, maxlen);
                    }
                }
            }
        }
        return res;
    }
};