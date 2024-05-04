class Solution {
public:
    bool isMatch(string s, string p) {
        string t = "";
        for (auto c : p){
            if (c != '*' || t[t.size()-1] != '*'){
                t += c;
            }
        }
        p = t;
        int n = s.size(), m = p.size();
         s = ' ' + s, p = ' ' + p;
         vector<vector<bool>> f(n+1, vector<bool>(m+1));
         f[0][0] = 1;
         for (int i = 0; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (j+1 <= m && p[j+1] == '*'){
                    //如果现在枚举的是a*中的a，则先跳过，因为a*要作为整体来看
                    continue;
                }
                if (i != 0 && p[j] != '*') {
                    f[i][j] = f[i-1][j-1] && (s[i] == p[j] || p[j] == '.');
                }else if (p[j] == '*'){
                    f[i][j] = f[i][j-2] || (i && f[i-1][j] && (s[i] == p[j-1] || p[j-1] == '.'));
                }
            }
         }

         return f[n][m];
    }
};