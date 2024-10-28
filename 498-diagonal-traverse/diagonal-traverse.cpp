class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> res;
        for (int i = 0; i < n+m-1; i++){
            //枚举对角线
            if (i % 2 == 0){
                //说明往上走
                for (int j = min(i, n-1); j >= max(0, i-m+1); j--) res.push_back(mat[j][i-j]);
            }else{
                for (int j = max(0, i-m+1); j <= min(i, n-1); j++) res.push_back(mat[j][i-j]);
            }
        }
        return res;
    }
};