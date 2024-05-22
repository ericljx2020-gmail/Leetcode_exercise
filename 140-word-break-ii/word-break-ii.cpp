class Solution {
public:
    unordered_map<string, bool> hash;
    int n;
    vector<bool> f;
    vector<string> res;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        f.resize(n+1);
        f[n] = 1;

        for (auto w : wordDict){
            hash[w] = 1;
        }

        for (int i = n-1; i != 0; i--) {
            for (int j = i; j < n; j++) {
                if (f[j+1] && hash[s.substr(i, j-i+1)]){
                    f[i] = 1;
                }
            }
        }

        dfs(s, 0, "");
        return res;
    }

    void dfs(string s, int u, string path) {
        if (u == n){
            path.pop_back();            //去掉多余空格
            res.push_back(path);
            return;
        }

         for (int i = u; i < n; i++) {
            if (hash[s.substr(u, i-u+1)] && f[i+1]){
                dfs(s, i+1, path + s.substr(u, i-u+1) + " ");
            }
         }
    }
};