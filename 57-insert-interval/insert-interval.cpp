class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> res;
        int n = intervals.size();
        int tt = -1, hh = -1;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++){
            if (intervals[i][0] <= tt){
                tt = max(tt, intervals[i][1]);
            }else{
                if (hh != -1) res.push_back({hh, tt});
                hh = intervals[i][0];
                tt = intervals[i][1];
            }
        }
        res.push_back({hh, tt});
        return res;
    }
};