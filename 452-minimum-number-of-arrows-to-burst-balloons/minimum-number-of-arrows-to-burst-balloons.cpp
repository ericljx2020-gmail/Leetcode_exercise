class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if (a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& p) {
        int n = p.size();
        sort(p.begin(), p.end(), cmp);
        int i = 0;
        int res = 0;
        while (i < n){
            int j = i+1;
            while (j < n && p[j][0] <= p[i][1]){
                j++;
            }
            //j is either > n or can't be bursted with previous
            i = j;
            res++;
        }
        return res;
    }
};