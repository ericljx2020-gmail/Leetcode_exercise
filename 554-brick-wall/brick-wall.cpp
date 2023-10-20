class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> hash;
        int n = wall.size();
        int len = 0;
        for (int j = 0; j < wall[0].size(); j++){
            len += wall[0][j];
        }
        for (int i = 0; i < n; i++){
            int pre = 0;
            for (int j = 0; j < wall[i].size(); j++){
                hash[pre+wall[i][j]]++;
                pre += wall[i][j];
            }   
        }
        int res = 0;
        for (auto a : hash){
            if (a.second > res && a.first != len){
                res = a.second;
            }
            cout << a.first << " " << a.second << "\n";
        }
        return n-res;
    }
};