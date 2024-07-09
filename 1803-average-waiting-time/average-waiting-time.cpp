class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int t = 0;
        double tot = 0;
        for (auto c : customers){
            tot += c[1];            //等蛋糕的时间一定会等
            tot += max(0, t-c[0]);      //如果等着了要加上
            t = max(t, c[0]) + c[1];
        }
        return tot / (int) customers.size();
    }
};