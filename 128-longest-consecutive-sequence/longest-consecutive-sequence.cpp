class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hash, vis;
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++){
            hash[nums[i]] = 1;
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (!vis[nums[i]]){
                int cur = 1;
                vis[nums[i]] = 1;
                int l = nums[i]-1, r = nums[i]+1;
                while (l >= 0 && hash[l]){
                    vis[l] = 1;
                    cur++;
                    l--;
                }
                while (r < n && hash[r]){
                    vis[r] = 1;
                    cur++;
                    r++;
                }
                res = max(res, cur);
            }
        }

        return res;
    }
};