class Solution {
public:
    const int N = 4e5+20;
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> v(N, 0), f(N, 0);
        startPos += 1;
        for (auto fr : fruits){
            v[fr[0]+1] = fr[1];
        }
        for (int i = 1; i <= 2e5+1; i++){
            f[i] = f[i-1] + v[i];
        }
        int res = 0;
        for (int i = startPos, j = max(1, i-k); j <= startPos && i <= 4e5; i++){
            int shortside = min(i - startPos, startPos - j);
            int longside = max(i - startPos, startPos - j);
            while (j <= startPos && 2 * shortside + longside > k){
                j++;
                shortside = min(i - startPos, startPos - j);
                longside = max(i - startPos, startPos - j);
            }
            if (j <= startPos){
                res = max(res, f[i]-f[j-1]);
                // cout << j << " " << i << " " << f[i] - f[j-1] << "\n";
            }
        }
        return res;
    }
};