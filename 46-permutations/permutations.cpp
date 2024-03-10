class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    unordered_map<int, bool> hash;

    void dfs(int c, int n, vector<int>& nums){
        if (c >= n){
            res.push_back(cur);
            return ;
        }

        for (int i = 0; i < n; i++){
            int a = nums[i];
            if (hash[a]) continue;
            hash[a] = 1;
            cur.push_back(a);
            dfs(c+1,n,nums);
            cur.pop_back();
            hash[a] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        dfs(0, n, nums);
        return res;
    }
};