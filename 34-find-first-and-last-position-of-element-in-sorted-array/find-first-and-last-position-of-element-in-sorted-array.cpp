class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        if (n == 0) return {-1,-1};
        vector<int> res(2,-1);
        while (l < r){
            int mid = l + r >> 1;
            if (nums[mid] >= target){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        if (nums[r] == target) res[0] = r;

        l = 0, r = n-1;
        while (l < r){
            int mid = l + r + 1>> 1;
            if (nums[mid] <= target){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        if (nums[r] == target) res[1] = r;
        return res;
    }
};