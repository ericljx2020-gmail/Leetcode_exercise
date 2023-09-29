class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool dec = true, asc = true;
        for (int i = 1; i < n; i++){
            if (nums[i] < nums[i-1]) {
                asc = false;
                break;
            }
        }
        for (int i = 1; i < n; i++){
            if (nums[i] > nums[i-1]) {
                dec = false;
                break;
            }
        }
        return (asc || dec);
    }
};