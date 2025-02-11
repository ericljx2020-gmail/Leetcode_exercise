class Solution {
public:

    static bool cmp(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int t = INT_MIN;
        int cnt = 0;
        for (int i = 0; i < intervals.size(); i++){
            if (intervals[i][0] < t){
                continue;
            }else{
                cnt++;
                t = intervals[i][1];
            }
        }
        return intervals.size() - cnt;
    }
};