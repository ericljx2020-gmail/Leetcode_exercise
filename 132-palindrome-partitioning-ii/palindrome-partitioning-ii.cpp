class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<vector<int>> f(n+1, vector<int> (n+1, 0));
        vector<int> g(n+1, INT_MAX);
        for (int l = 1; l <= n; l++){
            for (int i = 1; i + l - 1 <= n; i++){
                int j = i+l-1;
                if (l == 1) f[i][j] = 1;
                else if (l == 2) f[i][j] = (s[i] == s[j]);
                else f[i][j] = (f[i+1][j-1] && s[i] == s[j]);
            }
        }   
        g[0] = -1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i; j++){
                if (f[j][i]) g[i] = min(g[i], g[j-1] + 1);
            }
        }
        return g[n];
    }
};