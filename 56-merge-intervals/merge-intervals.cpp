class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }

    vector<vector<int>> merge(vector<vector<int>>& c) {
        sort(c.begin(), c.end(), cmp);
        vector<vector<int>> res;
        int l = -1, r = -1;
        for (int i = 0; i < c.size(); i++) {
            if (c[i][0] <= r){
                r = max(r, c[i][1]);
            }else{
                if (l != -1 && r != -1) res.push_back({l,r});
                l = c[i][0], r = c[i][1];
            }
        }
        res.push_back({l,r});
        return res;
    }
};