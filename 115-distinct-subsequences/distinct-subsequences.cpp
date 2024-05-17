typedef long long ll;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        s = ' ' + s;
        t = ' ' + t;
        vector<vector<ll>> f(n+1, vector<ll> (m+1, 0));
        for (int i = 0; i <= n; i++) f[i][0] = 1;
        //初始化要想清楚，s[i]和t[0]永远只有一种匹配方法
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = f[i-1][j];
                if (s[i] == t[j]) f[i][j] += f[i-1][j-1];
                f[i][j] %= INT_MAX;
            }
            // puts("");
        }
        return f[n][m];
    }
};