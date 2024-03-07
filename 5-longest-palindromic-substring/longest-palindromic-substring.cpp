class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") return "";
        int n = s.size();
        vector<vector<int>>f(n, vector<int>(n));
        f[n-1][n-1] = 1;
        for (int i = 0; i < n-1; i++) {
            f[i][i] = 1;
            if (s[i] == s[i+1]) f[i][i+1] = 1;
        }
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i < n; i++){
                int j = i + k - 1;
                if (j >= n) break;
                if (s[i] == s[j] && f[i+1][j-1]) f[i][j] = 1; 
            }
        }
        int res = 0;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (f[i][j] && j-i+1 > res){
                    res = j-i+1;
                    x = i, y = j;
                }
            }
        }
        return s.substr(x, res);
    }
};