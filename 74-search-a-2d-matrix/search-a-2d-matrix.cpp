class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = m*n-1;
        while (l < r){
            int mid = l + r >> 1;
            int x = mid / m, y = mid % m;
            if (matrix[x][y] >= target) r = mid;
            else l = mid+1;
        }
        
        int x = l / m, y = l % m;
        if (matrix[x][y] == target) return true;
        return false;
    }
};