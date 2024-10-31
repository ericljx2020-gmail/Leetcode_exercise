class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto c : intervals) {
            if (pq.size() && c[0] >= pq.top()){
                pq.pop();
            }

            pq.push(c[1]);
        }
        return pq.size();
    }
};