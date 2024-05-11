class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        //f[i][j][k]: s1以i，s2以j开始长度为k的区间可否合并，区间dp从小区间推断到大区间
        vector<vector<vector<bool>>> f(n, vector<vector<bool>> (n, vector<bool> (n+1)));
        for (int k = 1; k <= n; k++) {
            for (int i = 0; i+k-1 < n; i++) {
                for (int j = 0; j+k-1 < n; j++) {
                    if (k == 1) f[i][j][k] = (s1[i] == s2[j]);
                    else{
                        for (int u = 1; u < k; u++) {
                            if (f[i][j][u] && f[i+u][j+u][k-u] || f[i][j+k-u][u] && f[i+u][j][k-u]){
                                f[i][j][k] = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return f[0][0][n];
    }
};