class Solution {
public:
    const int N = 1e6+6;

    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> f(N, 0);
        for (auto c : intervals) {
            f[c[0]+1]++;
            f[c[1]+1]--;
        }
        int res = 0;
        for (int i = 1; i <= 1e6; i++){
            f[i] += f[i-1];
            res = max(res, f[i]);
        } 
        return res;
    }
};