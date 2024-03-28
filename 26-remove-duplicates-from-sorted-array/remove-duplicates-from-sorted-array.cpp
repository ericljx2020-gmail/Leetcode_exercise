class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
        return nums.size();
    }
};