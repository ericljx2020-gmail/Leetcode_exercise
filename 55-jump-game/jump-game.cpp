class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        for (int i = 0; i < n; i++){
            if (i == 0) cur = nums[i];
            cur--;
            if (cur <= 0 && nums[i] <= 0 && i != n-1) return false;
            cur = max(cur, nums[i]);
        }
        return true;
    }
};