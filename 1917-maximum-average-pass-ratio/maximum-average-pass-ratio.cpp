class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < classes.size(); i++){
            double idx = (double) (classes[i][1] - classes[i][0]) / ((double)classes[i][1] * (classes[i][1]+1));
            pq.push({idx, i});
        }

        while (extraStudents--) {
            auto t = pq.top();
            pq.pop();

            classes[t.second][0]++;
            classes[t.second][1]++;
            pair<double, int> p = {((double)classes[t.second][1] - classes[t.second][0]) / ((double)classes[t.second][1] * (classes[t.second][1]+1)), t.second};
            pq.push(p);
        }
        double sum = 0;
        for (auto c : classes){
            sum += (double) c[0] / c[1];
        }
        return sum / classes.size();
    }
};