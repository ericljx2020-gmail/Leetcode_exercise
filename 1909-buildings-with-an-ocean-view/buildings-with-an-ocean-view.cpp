class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int maxh = 0;
        int p = 0;
        vector<int> res;
        for (int i = heights.size()-1; i >= 0; i --) {
            if (heights[i] > maxh){
                maxh = heights[i];
                p = i;
                res.push_back(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};