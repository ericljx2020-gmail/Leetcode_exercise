class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (l < r){
            int k = l + r + 1 >> 1;
            if (nums[k] <= target){
                l = k;
            }else{
                r = k-1;
            }
        }
        int rr = -1;
        if (r >= 0 && r < n) rr = nums[r] == target ? r : -1;
        l = 0, r = n-1;
        while (l < r){
            int k = l + r >> 1;
            if (nums[k] >= target){
                r = k;
            }else{
                l = k+1;
            }
        }
        if (r < n && r >= 0) r = nums[r] == target ? r : -1;
        return {r, rr};
    }
};