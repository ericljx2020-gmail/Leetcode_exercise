class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return nums[(r+1) % n];
    }
};