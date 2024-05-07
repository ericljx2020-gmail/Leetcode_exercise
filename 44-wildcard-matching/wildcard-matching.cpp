class Solution {
public:
    //思路：f[i][j]表示s的前i个字符和p的前j个字符能否匹配
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> f(n+1, vector<int> (m+1, 0));
        s = ' ' + s, p = ' ' + p;
        f[0][0] = 1;            //两个都是空一定可以匹配
        // if (p[1] == '*') f[0][1] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j] == '?') f[i][j] = i && f[i-1][j-1];             //如果当前p里面是一个问号那么只需要s[1,i-1],p[1,j-1]匹配，i和j一定能匹配
                else if (p[j] == '*'){
                    //如果p[j]是一个*那么只要s[1,i]有p[1,j-1]这个前缀即可
                    f[i][j] = f[i][j-1] || (i && f[i-1][j]) || (i && f[i-1][j-1]);                //s[1,i] 匹配 p[1,j-1]说明p[j]作为空字符串 ｜ s[1,i-1]和p[1,j]匹配，这种情况包括了s中有p[j-1]作为前缀的情况因为当s[1,i]恰好匹配上p[1,j-1]的时候，f[i][j] = 1, 由于我们有第一个逻辑会把*当作空字符串因此逻辑成立
                }else{
                    f[i][j] = i && f[i-1][j-1] && (s[i] == p[j]);
                }
            }
        }

        // for (int i = 0; i <= n; i++){
        //     for (int j = 0; j <= m; j++){
        //         cout << f[i][j] << " ";
        //     }
        //     puts("");
        // }

        return f[n][m];
    }
};