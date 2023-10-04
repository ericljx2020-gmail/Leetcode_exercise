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
        int pre = -1;
        for (int i = u; i < candidates.size(); i++) {
            if (pre != -1 && candidates[i] == pre) continue;
            sum += candidates[i];
            cur.push_back(candidates[i]);
            dfs(i+1, candidates, target);
            sum -= candidates[i];
            cur.pop_back();
            pre = candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target);
        return res; 
    }
};