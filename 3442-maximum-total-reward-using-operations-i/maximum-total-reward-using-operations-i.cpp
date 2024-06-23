class Solution {
public:
    int maxTotalReward(vector<int>& w) {
        sort(w.begin(), w.end());
        w.erase(unique(w.begin(), w.end()), w.end());
        int n = w.size();
        w.insert(w.begin(), 0);
        vector<vector<int>> f(n+1, vector<int> (4001, 0));
        int maxv = 0;
        f[0][0] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 4000; j >=0; j--){
                f[i][j] = f[i-1][j];
                if (j >= w[i] && j - w[i] < w[i]) f[i][j] |= f[i-1][j-w[i]];
                maxv = max(maxv, (f[i][j]) * j);
            }
        }
        return maxv;
    }
};