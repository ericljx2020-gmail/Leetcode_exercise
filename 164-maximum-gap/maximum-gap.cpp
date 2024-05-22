class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int res = INT_MIN;
        for (int i = 0; i < n-1; i++){
            res = max(res, abs(nums[i] - nums[i+1]));
        }
        return res;
    }
};