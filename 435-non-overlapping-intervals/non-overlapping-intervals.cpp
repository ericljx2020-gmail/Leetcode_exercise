class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if (a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        int n = inter.size();
        sort(inter.begin(), inter.end(), cmp);
        int i = 0;
        int res = 0;
        while (i < n){
            int j = i + 1;
            while (j < n && inter[j][0] < inter[i][1]){
                j++;
            }
            // j is the one that can's be overlapp by i
            res += (j-i-1);
            i = j;
        }
        return res;
    }
};