class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> row, col;
        unordered_set<string> ss;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++){
            string s = "";
            for (int j = 0; j < m; j++){
                s += to_string(grid[i][j]) + " ";
            }
            row[s]++;
            ss.insert(s);
        }

        for (int i = 0; i < m; i++){
            string s = "";
            for (int j = 0; j < n; j++){
                s += to_string(grid[j][i]) + " ";
            }
            col[s]++;
            ss.insert(s);
        }   
        int res = 0;
        for (auto c : ss) {
            res += row[c] * col[c];
        }
        return res;
    }
};