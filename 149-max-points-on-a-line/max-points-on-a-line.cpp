class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; i++){
            unordered_map<double, int> hash;
            auto a = points[i];
            for (int j = 0; j < n; j++){
                if (i == j) continue;
                auto b = points[j];
                double k = (double)(a[1] - b[1]) / (double)(a[0]-b[0]);
                hash[k]++;
                res = max(res, hash[k]);
            }
        }
        return res+1;
    }
};