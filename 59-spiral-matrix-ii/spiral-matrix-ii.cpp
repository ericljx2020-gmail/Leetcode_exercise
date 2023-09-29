class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};     //右下左上
    vector<vector<int>> generateMatrix(int n) {
        int x = 0, y = 0, idx = 0;
        int cnt = 0;
        unordered_map<int,unordered_map<int,bool>> hash;
        vector<vector<int>> f(n, vector<int>(n, 0));
        bool flag = false;
        while (true) {
            if (cnt == n * n){
                break;
            } 
            int nx = x + dx[idx % 4], ny = y + dy[idx % 4];
            if (!flag) nx = ny = 0, flag = true;
            if (nx >= n || nx < 0 || ny >= n || ny < 0 || hash[nx][ny]) {
                idx++;
                continue;
            }
            hash[nx][ny] = 1;
            x = nx, y = ny;
            f[x][y] = ++cnt;
            
        }
        return f;
    }
};