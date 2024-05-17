class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++){
            res.push_back({1});
        }
        for (int i = 0; i < numRows-1; i++) {
            for (int j = 0; j < res[i].size()-1; j++) {
                res[i+1].push_back(res[i][j] + res[i][j+1]);
            }
            res[i+1].push_back(1);
        }
        return res;
    }
};