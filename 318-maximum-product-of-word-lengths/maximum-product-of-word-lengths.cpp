class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> st(n, vector<int> (26, 0));
        for (int i = 0; i < n; i++){
            string s = words[i];
            for (auto c : s) {
                st[i][c-'a'] = 1;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++){
                string s1 = words[i], s2 = words[j];
                int mask = 0;
                for (int k = 0; k < 26; k++){
                    mask = mask | (st[i][k] & st[j][k]);
                }
                if (mask == 0) res = max(res, (int) s1.size() * (int)s2.size());
            }
        }
        return res;
    }
};