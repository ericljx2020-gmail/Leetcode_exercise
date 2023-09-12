class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f[n][2];
        memset(f, 0, sizeof f);
        f[0][0] = 0, f[0][1] = nums[0];
        for (int i = 1; i < nums.size(); i++){
            f[i][0] = max(f[i-1][0], f[i-1][1]);        //当前不偷，前一个可以偷或者不偷
            f[i][1] = f[i-1][0] + nums[i];
        }
        return max(f[nums.size()-1][0], f[nums.size()-1][1]);
    }
};