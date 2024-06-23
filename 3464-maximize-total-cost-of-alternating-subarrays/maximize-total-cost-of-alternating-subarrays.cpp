class Solution {
public:
    long long maximumTotalCost(vector<int>& a) {
        //dp思路：在第i个位置考虑是否已i为一个subarray的开始
        //f[i][0]: 第i个位置不变号
        //f[i][1]: 第i为位置变号
        //有了这个我们可以想到f[i][0]只有两种可能就是f[i+1][1]
        int n = a.size();
        a.insert(a.begin(), 0);
        vector<vector<long long>> f(n+2, vector<long long> (2, 0));

        for (int i = n; i >= 0; i--){
            f[i][0] = max(f[i+1][1] + a[i],f[i+1][0] + a[i]);
            f[i][1] = max(f[i+1][1] + a[i], f[i+1][0] - a[i]);
        }
        return f[1][0];
    }
};