class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1,-1};
        int l = 0, r = n - 1;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        int right = r;
        if (nums[r] == target) right = r;
        else right = -1;
        l = 0, r = n-1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        if (nums[l] != target) l = -1;
        return {l, right};
    }
};