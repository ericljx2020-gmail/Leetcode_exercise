class Solution {
public:
    unordered_map<int, int> hash;

    int dfs(int u, int k, int step, vector<int>& nums){
        if (nums[k] == u) return hash[k] = step;
        // cout << u << " " << k << " " << step << endl;
        return hash[k] = dfs(u, nums[k], step+1, nums);
    }

    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (!hash[i]){
                hash[i] = dfs(nums[i], nums[i], 1, nums);
            }
        }
        int maxv = 0;
        for (int i = 0; i < n; i++){
            // cout << hash[i] << " " ;
            maxv = max(maxv, hash[i]);
        }
        return maxv;
    }
};