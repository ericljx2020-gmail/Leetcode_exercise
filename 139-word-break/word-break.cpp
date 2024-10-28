class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> f(n+1, 0);
        s = " " + s;
        f[0] = 1;
        unordered_map<string, bool> hash;
        for (auto w : wordDict){
            hash[w] = 1;
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i; j++){
                f[i] |= f[j-1] && hash[s.substr(j, i-j+1)];
            }
        }
        return f[n];
    }
};