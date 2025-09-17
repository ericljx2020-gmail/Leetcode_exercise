class Solution {
public:

    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(), a.end(), cmp);
        int s = a[0][0], t = a[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < n; i++){
            if (a[i][0] <= t){
                t = max(t, a[i][1]);
            }else{
                res.push_back({s,t});
                s = a[i][0];
                t = a[i][1];   
            }
        }
        res.push_back({s,t});
        return res;
    }
};