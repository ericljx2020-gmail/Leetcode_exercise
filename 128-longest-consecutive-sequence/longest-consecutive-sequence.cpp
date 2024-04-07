class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++){
            hash[nums[i]] = 1;
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (!hash[nums[i]-1]){
                int cur = 1;
                int r = nums[i]+1;
                while (hash[r]){
                    cur++;
                    r++;
                }
                res = max(res, cur);
            }
        }

        return res;
    }
};