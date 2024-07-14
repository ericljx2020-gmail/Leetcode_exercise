class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int res = 0;
        unordered_map<int, int> hash;
        unordered_set<int> st;
        for (int i = 0, j = 0; i < n; i++){
            if (hash[nums[i]]){
                while (j < i && hash[nums[i]]){
                    sum -= nums[j];
                    hash[nums[j]]--;
                    j++;
                }
            }
            hash[nums[i]]++;
            sum += nums[i];
            res = max(res, sum);
        }
        return res;
    }
};