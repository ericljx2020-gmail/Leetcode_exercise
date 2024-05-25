class Solution {
public:
    vector<bool> f;
    unordered_map<string, bool> hash;
    vector<string> res;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        f.resize(n+1);
        f[n] = 1;
        //f[i]指的是s[i,n]能否组成
        for (auto w : wordDict) {
            hash[w] = 1;
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= i; j--) {
                if (f[j+1] && hash[s.substr(i, j-i+1)]){
                    f[i] = true;
                    break;
                }
            }
        }
        // for (int i = 0; i < n; i++) cout << f[i] << " " ;

        dfs(s, 0, "");
        return res;
    }

    void dfs(string s, int u, string path) {
        if (u == s.size()) {
            path.pop_back();
            res.push_back(path);
            return;
        }

        for (int i = u; i < s.size(); i++) {
            if (hash[s.substr(u, i-u+1)] && f[i+1]) dfs(s, i+1, path+s.substr(u,i-u+1)+" ");
        }
    }
};