class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    unordered_map<int,bool> hash;
    void dfs(int x, int n, vector<int> nums){
        if (x >= n){
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < n; i++){
            if (hash[i]) continue;
            cur.push_back(nums[i]);
            hash[i] = 1;
            dfs(x+1,n,nums);
            cur.pop_back();
            hash[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        dfs(0,n,nums);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};