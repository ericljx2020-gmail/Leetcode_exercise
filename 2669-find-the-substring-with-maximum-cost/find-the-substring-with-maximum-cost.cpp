class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size();
        s = " " + s;
        unordered_map<char, int> hash;
        for (char i = 'a'; i <= 'z'; i++){
            hash[i] = i-'a'+1;
        }
        for (int i = 0; i < chars.size(); i++){
            hash[chars[i]] = vals[i];
        }
        vector<int> f(n+1, 0);
        int res = 0;
        for (int i = 1; i <= n; i++){
            f[i] = max(f[i-1], 0) + hash[s[i]];
            res = max(res, f[i]);
        }
        return res;
    }
};