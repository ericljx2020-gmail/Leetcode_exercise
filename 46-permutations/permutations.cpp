class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    unordered_map<int, bool> hash;
    void dfs(int u, vector<int>& nums){
        if (u == nums.size()){
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (hash[nums[i]]) continue;
            hash[nums[i]] = 1;
            cur.push_back(nums[i]);
            dfs(u+1, nums);
            hash[nums[i]] = 0;
            cur.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(0,nums);
        return res;
    }
};