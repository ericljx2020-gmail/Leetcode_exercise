class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), cmp);
        int ans = 0, prev = 0;
        for (int i = 0; i < tasks.size(); i++){
            auto t = tasks[i];
            if (t[1] > prev){
                ans += t[1] - prev;
                prev = t[1];
            }
            prev -= t[0];
        }
        return ans;
    }

    static bool cmp(vector<int> a, vector<int> b){
        return a[1] - a[0] > b[1] - b[0];
    }
};