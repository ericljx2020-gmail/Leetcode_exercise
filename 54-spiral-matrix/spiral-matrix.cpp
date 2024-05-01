class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_map<int, unordered_map<int,int>> hash;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        int idx = 0;
        int i = 0, j = 0;
        int d = 0;
        vector<int> res;
        while (idx < n * m){
            res.push_back(matrix[i][j]);
            hash[i][j] = 1;
            idx++;
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (hash[ni][nj] || ni >= n || nj >= m || ni < 0 || nj < 0){
                d += 1;
                d %= 4;
                ni = i+dx[d];
                nj = j+dy[d];
            }
            i = ni, j = nj;
        }
        return res;
    }
};