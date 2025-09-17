class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int n = nums.size();
        vector<string> res;
        int l = 0, r = 1;
        while (r < n){
            if (nums[r] != nums[r-1] + 1){
                string cur = to_string(nums[l]);
                if (l != r-1) cur = to_string(nums[l]) + "->" + to_string(nums[r-1]);
                res.push_back(cur);
                l = r;
            }
            r++;
        }
        string cur = to_string(nums[l]);
        if (l != r-1) cur = to_string(nums[l]) + "->" + to_string(nums[r-1]);
        res.push_back(cur);
        return res;
    }
};