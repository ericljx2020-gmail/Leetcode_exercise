class Solution {
public:
    vector<int> res, toppingCosts;
    int cls = 0;
    int target;
    int minD = INT_MAX;
    void dfs(int s, int t, int c) {
        if (s == t){
            int o = c;
            int cur = c;
            for (int i = 0; i < res.size(); i++){
                cur += res[i] * toppingCosts[i];
            }
            if (abs(cur - target) < minD || (abs(cur - target) == minD && cur < cls)){
                minD = abs(cur - target);
                cls = cur;
            }
            return;
        }

        for (int i = 0; i <= 2; i++) {
            res.push_back(i);
            dfs(s+1,t, c);
            res.pop_back();
        }
    }

    int closestCost(vector<int>& baseCosts, vector<int>& _toppingCosts, int _target) {
        target = _target;
        int m = _toppingCosts.size();
        toppingCosts = _toppingCosts;
        for (int i = 0; i < baseCosts.size(); i++){
            int c = baseCosts[i];
            dfs(0,m,c);
        }
        return cls;
    }
};