class Solution {
public:
    vector<vector<string>> res;
    vector<string> cur;
    string s;
    vector<vector<string>> partition(string _s) {
        s = _s;
        int n = s.size();
        vector<vector<bool>> f(n+1, vector<bool> (n+1, 0));
        s = ' ' + s;
        for (int l = 1; l <= n; l ++) {
            for (int i = 1; i + l - 1 <= n; i++){
                int j = i+l-1;
                if (l == 1){
                    f[i][j] = 1;
                }else if (l == 2){
                    f[i][j] = (s[i] == s[j]);
                }else{
                    f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
                }
                // cout << f[i][j] << " ";
            }
            // puts("");
        }
        dfs(1, n, f); 
        return res;
    }

    void dfs(int l, int n, vector<vector<bool>> f) {
        if (l > n){
            res.push_back(cur);
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (f[l][i]){
                cur.push_back(s.substr(l, i-l+1));
                dfs(i+1, n, f);
                cur.pop_back();
            }
        }
    }
};