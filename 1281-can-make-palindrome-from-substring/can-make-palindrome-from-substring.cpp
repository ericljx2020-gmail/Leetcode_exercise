class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        s = ' ' + s;
        vector<vector<int>> f(n+1, vector<int> (26, 0));

        for (int i = 1; i <= n; i++){
            for (int j = 0; j < 26; j++){
                f[i][j] = f[i-1][j] + (s[i]-'a' == j);
                // cout << f[i][j] << " ";
            }
            // puts("");
        }

        vector<bool> res;
        for (auto q : queries){
            int l = q[0]+1, r = q[1]+1, k = q[2];
            int odd = 0;
            for (int i = 0; i < 26; i++){
                if ((f[r][i]-f[l-1][i]) & 1){
                    odd++;
                }
            }
            res.push_back((odd / 2) <= k);
        }

        return res;
    }
};