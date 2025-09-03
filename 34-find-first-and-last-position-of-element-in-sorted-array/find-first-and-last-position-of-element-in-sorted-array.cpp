class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};
        int n = nums.size();
        // find right
        int l = 0, r = n-1;
        while (l < r){
            int mid = l + r >> 1;
            if (nums[mid] >= target){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        if (nums[r] != target) return {-1, -1};
        vector<int> res;
        res.push_back(r);
        l = 0, r = n-1;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        res.push_back(r);
        return res;
    }
};