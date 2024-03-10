class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(int sum, int p, int n, int target, vector<int>& candidates) {
        if (sum > target){
            return;
        }
        if (sum == target){
            res.push_back(cur);
            return;
        }

        for (int i = p; i < n; i++){
            cur.push_back(candidates[i]);
            sum += candidates[i];
            dfs(sum, i, n, target, candidates);
            sum -= candidates[i];
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        dfs(0, 0, n, target, candidates);
        return res;
    }
};