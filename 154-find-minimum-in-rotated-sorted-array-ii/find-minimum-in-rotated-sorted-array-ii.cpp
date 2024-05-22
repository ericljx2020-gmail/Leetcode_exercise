class Solution {
public:
    int findMin(vector<int>& nums) {
        int minv = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            minv = min(minv, nums[i]);
        }
        return minv;
    }
};