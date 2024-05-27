class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        long long res = 0;
        int n = bl.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++){
                int urx = min(tr[i][0], tr[j][0]);
                int ury = min(tr[i][1], tr[j][1]);
                int blx = max(bl[i][0], bl[j][0]);
                int bly = max(bl[i][1], bl[j][1]);
                if (urx - blx <= 0 || ury - bly <= 0) continue;
                int shortside = min(urx-blx, ury-bly);
                res = max(res,(long long)shortside*shortside);
            }
        }
        return res;
    }
};