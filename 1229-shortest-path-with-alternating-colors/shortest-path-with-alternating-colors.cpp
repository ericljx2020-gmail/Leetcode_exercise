class Solution {
public:
    const int N = 100;
    vector<vector<int>> red, blue;
    vector<int> b, r, v;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        red.resize(n+1);
        blue.resize(n+1);
        b.resize(n+1, -1);
        r.resize(n+1, -1);
        for (auto edge : redEdges){
            // if (edge[0] == edge[1]) continue;           //自环不用放进去
            red[edge[0]].push_back(edge[1]);
        }
        for(auto edge : blueEdges){
            // if (edge[0] == edge[1]) continue;
            blue[edge[0]].push_back(edge[1]);
        }
        // unordered_map<int, unordered_map<int, unordered_map<int, bool>>> st;
        queue<vector<int>> q;
        q.push({0, 0, 0});
        q.push({0, 0, 1});
        r[0] = 0;
        b[0] = 0;
        // st[0] = 1;
        //从红边开始
        while (q.size()){
            auto t = q.front();
            q.pop();
            // cout << t.first << " " << t.second << '\n';
            int color = t[2];
            if (color){
                for (int i = 0; i < blue[t[0]].size(); i++){
                    int j = blue[t[0]][i];
                    if (b[j] == -1){
                        // st[t.first][j][color] = 1;
                        b[j] = t[1]+1;
                        q.push({j, t[1]+1, color^1});
                    }
                }
            }else{
                for (int i = 0; i < red[t[0]].size(); i++){
                    int j = red[t[0]][i];
                    if (r[j] == -1){
                        // st[t.first][j][color] = 1;
                        r[j] = t[1]+1;
                        q.push({j, t[1]+1, color^1});
                    }
                }
            }
            // color ^= 1;
        }
        
        for (int i = 0; i < n; i++){
            if (r[i] == -1 && b[i] == -1){
                v.push_back(-1);
            }else if (r[i] == -1 || b[i] == -1){
                v.push_back(max(r[i], b[i]));
            }else{
                v.push_back(min(r[i], b[i]));
            }
        }
        // cout << r[2] << " " << b[2];
        return v;
    }
};