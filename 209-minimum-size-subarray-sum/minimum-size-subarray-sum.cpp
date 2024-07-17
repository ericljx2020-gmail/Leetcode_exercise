class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int res = INT_MAX;
        for (int i = 0, j = 0; i < n; i++){
            sum += nums[i];
            while (sum - nums[j] >= target){
                sum -= nums[j++];
            }
            if(sum >= target) res = min(res, i-j+1);
        }
        return res <= n ? res : 0;
    }
};