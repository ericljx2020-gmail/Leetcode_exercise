class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 0;
        sort(nums.begin(), nums.end());
        for (auto c : nums) cout << c << " ";
        return min(abs(nums[n-2]-nums[1]),min(abs(nums[n-3] - nums[0]), abs(nums[n-1]-nums[2])));
    }
};