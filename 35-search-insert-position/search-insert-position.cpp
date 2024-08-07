class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (nums[n-1] < target) return n;
        int l = 0, r = n-1;
        while (l < r ){
            int mid = l + r >> 1;
            if (nums[mid] >= target){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
};