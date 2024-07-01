class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> f(target+1, -0x3f3f3f3f);
        f[0] = 0;
        for (int i = 0; i < n; i++){
            for (int j = target; j >= nums[i]; j--){
                f[j] = max(f[j], f[j-nums[i]]+1);
            }
        }
        return f[target] < 0 ? -1 : f[target];
    }
};