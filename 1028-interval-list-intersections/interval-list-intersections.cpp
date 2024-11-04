class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> res;
        for (int i = 0, j = 0; i < f.size(); i++){
            while (j < s.size() && s[j][0] <= f[i][1]){
                int l = max(f[i][0], s[j][0]);
                int r = min(f[i][1], s[j][1]);
                if (l <= r) res.push_back({l,r});
                j++;
            }
            if (j > 0 )j--;
        }
        return res;
    }
};