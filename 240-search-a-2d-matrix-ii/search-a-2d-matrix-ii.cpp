class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size()-1, m = matrix[0].size();
        while(n >= 0) {
            if (matrix[n][0] <= target && matrix[n][m-1] >= target){
                for (int i = 0; i < m; i++){
                    if (matrix[n][i] == target) return true;
                    // cout << matrix[n][i] << " ";
                }
            }
            n--;
        }
        return false;
    }
};