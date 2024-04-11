class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    unordered_map<int, int>hash;
    void dfs(int x, int n, vector<int> nums){
        if (x >= n) {
            // cout << x << " ";
            vector<int>ref;
            for (int i = 0; i < n; i++) {
                if (cur[i]) ref.push_back(nums[i]);
            }
            res.push_back(ref);
            return;
        }

        for (int i = 0; i <= 1; i++){
            cur.push_back(i);
            dfs(x+1, n, nums);
            cur.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        dfs(0,n, nums);
        return res;
    }
};