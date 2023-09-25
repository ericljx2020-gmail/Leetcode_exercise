class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        for (int i = 0; i < n; i++){
            int a = intervals[i][0], b = intervals[i][1];
            int j = i+1;
            while (j < n && intervals[j][0] <= b){
                b = max(b, intervals[j][1]);
                j++;
            }
            res.push_back({a,b});
            i = j-1;
        }
        return res;
    }
};