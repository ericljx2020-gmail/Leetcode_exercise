class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<vector<int>> f(n+1, vector<int> (2, 0));
        for (int i = 1; i <= n; i++){
            f[i][0] = f[i-1][0] + (s[i] == '1');
            f[i][1] = min(f[i-1][1] + (s[i] == '0'), f[i-1][0] + (s[i] == '0'));
            // cout << f[i][0] << " " << f[i][1] << '\n';
        }
        return min(f[n][1], f[n][0]);
    }
};