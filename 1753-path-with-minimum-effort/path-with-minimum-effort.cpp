typedef vector<int> VI;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        unordered_map<int, unordered_map<int,bool>> st;
        priority_queue<VI, vector<VI>, greater<VI>> q;
        q.push({0,0,0});
        int dif[n][m];
        memset(dif, 0x3f, sizeof dif);

        while (q.size()){
            VI t = q.top();
            q.pop();
            st[t[1]][t[2]] = 1;
            if (t[1] == n-1 && t[2] == m-1) return t[0];
            for (int i = 0; i < 4; i++){
                int a = t[1] + dx[i], b = t[2] + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (st[a][b]) continue;

                int cur = max(t[0], abs(heights[a][b] - heights[t[1]][t[2]]));
                if (cur < dif[a][b]){
                    q.push({cur, a, b});
                    dif[a][b] = cur;
                }
                // cout << cur << " " << a << " " << b << "\n";
            }
        }
        return 0;
    }
};