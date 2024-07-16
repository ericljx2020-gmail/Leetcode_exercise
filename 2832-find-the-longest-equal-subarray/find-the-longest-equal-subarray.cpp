class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        int res = 0;
        for (int i = 0, j = 0; i < n; i++){
            hash[nums[i]]++;
            while (i-j+1 - hash[nums[i]] > k && hash[nums[i]] >= res){
                hash[nums[j++]]--;
                // cout << "ihn";
            }
            res = max(res, hash[nums[i]]);
        }
        return res;
    }
};