class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_map<int, unordered_map<int,bool>> hash;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!hash[i][j] && !hash[j][i]) {
                    swap(matrix[i][j], matrix[j][i]);
                    hash[i][j] = hash[j][i] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m/2; j++){
                swap(matrix[i][j], matrix[i][m-j-1]);
            }
        }
        return;
    }
};