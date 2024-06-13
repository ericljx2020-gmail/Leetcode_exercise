class Solution {
public:
    int maxDotProduct(vector<int>& s1, vector<int>& s2) {
        int n = s1.size(), m = s2.size();
        s1.insert(s1.begin(), 0);
        s2.insert(s2.begin(), 0);
        vector<vector<int>> f(n+1, vector<int> (m+1, 0));
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= m; j++){
                f[i][j] = -0x3f3f3f3f;
            }
        }
        for (int i = 1; i <= n; i++){
            f[i][1] = max(f[i-1][1], s1[i] * s2[1]);
            // cout << f[i][1] << " ";
        }
        // puts("");
        for (int i = 1; i <= m; i++){
            f[1][i] = max(f[1][i-1], s1[1] * s2[i]);
            // cout << f[1][i] << " ";
        }
        for (int i = 2; i <= n; i++){
            for (int j = 2; j <= m; j++){
                f[i][j] = max(f[i][j], f[i-1][j-1] + s1[i] * s2[j]);
                f[i][j] = max(f[i][j], max(f[i-1][j], f[i][j-1]));
                f[i][j] = max(f[i][j], s1[i] * s2[j]);
                cout << f[i][j] << " ";
            }
            puts("");
        }
        return f[n][m];
    }
};