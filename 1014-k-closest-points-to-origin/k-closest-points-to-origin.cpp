class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int, vector<vector<int>>> hash;
        vector<vector<int>> res;
        for (auto c : points){
            int d = c[0] * c[0] + c[1] * c[1];
            hash[d].push_back(c); 
        }
        vector<int> dis;
        for (auto c : hash){
            dis.push_back(c.first);
        }
        sort(dis.begin(), dis.end());
        int cnt = 0;
        for (int i = 0; i < dis.size(); i++){
            for (auto c : hash[dis[i]]){
                res.push_back(c);
                cnt++;
                if (cnt == k) return res;
            }
        }
        return {};
    }
};