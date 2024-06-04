class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> ss;
        for (int i = 0; i < n; i++){
            if (ss.find(nums[i]) != ss.end()) return true;
            ss.insert(nums[i]);
        }
        return false;
    }
};