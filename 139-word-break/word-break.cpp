class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> hash;
        int n = s.size();
        s = ' ' + s;
        vector<bool> f(n+1, 0);
        for (int i = 0; i < wordDict.size(); i++){
            hash[wordDict[i]] = 1;
        }

        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                string sub = s.substr(j, i-j+1);
                if (f[j-1] && hash[sub]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};