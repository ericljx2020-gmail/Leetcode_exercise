class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++){
            hash[nums[i]]++;
            if (hash[nums[i]] > n / 3){
                res.push_back(nums[i]);
                hash[nums[i]] = INT_MIN;
            }
        }
        return res;
    }
};