class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        //f[i]表示以i结尾的subarray乘积最大值
        //g[i]表示以i结尾乘积最小值
        vector<int> f(n, 0), g(n, 0);
        f[0] = nums[0], g[0] = nums[0];
        for (int i = 1; i < nums.size(); i++){
            f[i] = max(nums[i], max(f[i-1] * nums[i], g[i-1] * nums[i]));
            g[i] = min(nums[i], min(f[i-1] * nums[i], g[i-1] * nums[i]));
            res = max(res, f[i]);
        }
        return res;
    }
};