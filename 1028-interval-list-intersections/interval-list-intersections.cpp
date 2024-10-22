class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < n && j < m) {
            auto a = firstList[i], b = secondList[j];
            if (a[1] <= b[1]){
                int maxl = max(a[0], b[0]);
                if (maxl <= a[1]){
                    //there is intersection
                    res.push_back({maxl, a[1]});
                }
                i++;
            }else{
                int maxl = max(a[0], b[0]);
                if (maxl <= b[1]){
                    res.push_back({maxl, b[1]});
                }
                j++;
            }
        }
        return res;
    }
};