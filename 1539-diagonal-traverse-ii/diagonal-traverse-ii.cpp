class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        if (nums.size() == 0) return {};
        int n = nums.size(), m = nums[0].size();
        for (int i = 0; i < n; i++) m = max(m, (int)nums[i].size());
        // cout << n << " " << m;
        vector<int> res;
        vector<vector<int>> dg(n+m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < nums[i].size(); j++){
                //nums[j][i]
                // cout << nums[j][i] << " ";
                dg[j+i].push_back(nums[i][j]);
            }
        }
        for (int i = 0; i < m+n; i++){
            for (int j = dg[i].size()-1; j >= 0; j--){
                res.push_back(dg[i][j]);
            }
        }
        return res;
    }
};