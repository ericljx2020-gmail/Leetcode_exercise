class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = nums.size()-1;
        while (l < r){
            int mid = l + r >> 1;
            if (nums[mid] > nums[mid+1]) r = mid;
            else l = mid+1;
        }
        return r;
    }
};