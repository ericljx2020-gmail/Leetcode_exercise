class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            int j = i + 2;
            // int cnt = 1;
            while (j < nums.size() && nums[j] == nums[i]) {
                nums.erase(nums.begin() + j);
            }
        }
        return nums.size();
    }
};