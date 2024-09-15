class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> f(n, vector<int> (n, 0));
        //f[l][r]: (l,r)区间爆炸最大值
        for (int l = 3; l <= n; l++){
            for (int i = 0; i+l-1 < n; i++){
                int j = i+l-1;
                for (int k = i+1; k <= j-1; k++){
                    f[i][j] = max(f[i][k]+f[k][j]+nums[i] * nums[k] * nums[j], f[i][j]);
                }
            }
        }
        return f[0][n-1];
    }
};