class Solution {
public:
    int res = 0;
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        int l = 0, r = 1e9;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (check(mid, points, s)){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        check(r, points, s);
        return res;
    }

    bool check(int d, vector<vector<int>> points, string s){
        unordered_map<char, bool> hash;
        int cnt = 0;
        for (int i = 0; i < points.size(); i++){
            int x = points[i][0], y = points[i][1];
            if (x <= d && x >= -d && y <= d && y >= -d){
                //在方形
                if (hash[s[i]]) return false;
                hash[s[i]] = 1;
                cnt++;
            }
        }
        res = max(res, cnt);
        return true;
    }
};