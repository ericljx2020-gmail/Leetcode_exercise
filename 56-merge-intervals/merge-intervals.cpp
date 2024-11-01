class Solution {
public:

    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        vector<vector<int>> res;
        int s = intervals[0][0], t = intervals[0][1];
        for (int i = 1; i < n; i++){
            if (intervals[i][0] <= t){
                t = max(t, intervals[i][1]);
            }else{
                res.push_back({s,t});
                s = intervals[i][0];
                t = intervals[i][1];
            }
        }
        res.push_back({s,t});
        return res;
    }
};