class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    int sum = 0;
    void dfs(int u, vector<int>& candidates, int target) {
        if (sum > target){
            return;
        }
        if (sum == target){
            res.push_back(cur);
            return;
        }

        for (int i = u; i < candidates.size(); i++) {
            sum += candidates[i];
            cur.push_back(candidates[i]);
            dfs(i, candidates, target);
            sum -= candidates[i];
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       int n = candidates.size();
       sort(candidates.begin(), candidates.end());
       dfs(0, candidates, target);
       return res; 
    }
};