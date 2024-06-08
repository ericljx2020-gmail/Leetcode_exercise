class Solution {
public:
    unordered_map<int, unordered_map<int, int>> st;
    vector<vector<int>> g;
    int n,m;

    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    void bfs(int x, int y, int idx){
        queue<pair<int,int>> q;
        q.push({x,y});
        st[x][y] = idx;
        while (q.size()){
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int a = t.first+dx[i];
                int b = t.second+dy[i];
                if (a < 0 || a >= g.size() || b < 0 || b >= g[0].size()) continue;
                if (st[a][b]) continue;
                if (g[a][b] == 0) continue;
                q.push({a,b});
                st[a][b] = idx;
            }
        }
    }

    int findx(int x, int y){
        queue<pair<int, pair<int, int>>> q;
        int cc = st[x][y];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (st[i][j] == cc){
                    for (int k = 0; k < 4; k++){
                        int a = i+dx[k], b = j+dy[k];
                        if (a < 0 || a >= g.size() || b < 0 || b >= g[0].size()) continue;
                        if (g[a][b] == 0 && !st[a][b]){
                            q.push({1, {a,b}});
                            st[a][b] = 1;
                        }
                    }
                }
            }
        }

        while (q.size()) {
            auto t = q.front();
            q.pop();

            int step = t.first, xx = t.second.first, yy = t.second.second;
            for (int i = 0; i < 4; i++){
                int a = xx+dx[i];
                int b = yy+dy[i];
                if (a < 0 || a >= g.size() || b < 0 || b >= g[0].size()) continue;
                if (st[a][b] == 2 || st[a][b] == 1) continue;
                if (st[a][b] == 3) return step;
                q.push({step+1, {a,b}});
                st[a][b] = 1;
            }
        }
        return -1;
    }
    
    int shortestBridge(vector<vector<int>>& _g) {
        g = _g;
        n = g.size(), m = g[0].size();
        int idx = 2;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (g[i][j] == 1 && !st[i][j]){
                    // cout << idx << " ";
                    bfs(i,j, idx);
                    idx++;
                } 
            }
        }
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (g[i][j] == 1){
                    return findx(i,j);
                }
            }
        }
        return -1;
    }
    
};