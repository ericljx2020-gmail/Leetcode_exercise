class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int tt = -1, hh = -1;
        for (int i = 0; i < n; i++){
            if (intervals[i][0] <= tt){
                tt = max(tt, intervals[i][1]);
            }else{
                if (hh != -1)res.push_back({hh,tt});
                hh = intervals[i][0];
                tt = intervals[i][1];
            }
        }
        res.push_back({hh,tt});
        return res;
    }
};