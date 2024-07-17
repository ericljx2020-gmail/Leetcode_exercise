class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int n,m;
    vector<vector<int>> grid;
    int islandPerimeter(vector<vector<int>>& _grid) {
        grid = _grid;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    return bfs(i,j);
                }
            }
        }
        return 0;
    }

    int bfs(int x, int y){
        queue<pair<int,int>> q;
        q.push({x,y});
        unordered_map<int, unordered_map<int, bool>> st;
        st[x][y] = 1;
        int res = 0;

        while (q.size()){
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int a = t.first + dx[i];
                int b = t.second+ dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m){
                    res++;
                    continue;
                }
                if (st[a][b]) continue;
                if (grid[a][b] == 1 && !st[a][b]){
                    st[a][b] = 1;
                    q.push({a,b});
                }else{
                    res++;
                }
            }
        }
        return res;
    }
};