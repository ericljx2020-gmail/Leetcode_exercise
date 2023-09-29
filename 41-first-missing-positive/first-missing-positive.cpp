class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            hash[nums[i]] = 1;
        }
        for (int i = 1; i <= 1e5+5; i++){
            if (!hash[i]){
                return i;
            }
        }
        return 0;
    }
};