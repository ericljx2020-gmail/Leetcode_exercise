class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};
        int l = 0, r = nums.size()-1;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        int rr = r;

        l = 0, r = nums.size()-1;
        while (l < r){
            int mid = l + r >> 1;
            if (nums[mid] >= target){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        int ll = r;
        if (nums[ll] != target) return {-1,-1};
        return {ll, rr};
    }
};