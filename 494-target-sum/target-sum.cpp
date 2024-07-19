class Solution {
public:
    const int N = 2005;
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto c : nums) sum += c;
        int s = sum - target;
        if (s < 0 || s & 1) return 0;

        vector<int> f(N, 0);
        f[0] = 1;
        for (int i = 0; i < nums.size(); i++){
            for (int j = 2000; j >= nums[i]; j--){
                f[j] += f[j-nums[i]];
            }
        }
        return f[s / 2];
    }
};