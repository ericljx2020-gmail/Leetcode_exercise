class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_map<int, unordered_map<int, bool>> hash;
        int n = circles.size();
        int res = 0;
        for (auto c : circles) {
            int x = c[0], y = c[1], r = c[2];
            int u = x-r, d = x+r, l = y-r, rr = y+r;
            for (int i = u; i <= d; i++) {
                for (int j = l; j <= rr; j++) {
                    if (hash[i][j]) continue;
                    if (check(i,j,x,y,r)){
                        res++;
                        hash[i][j] = 1;
                    }
                }
            }
        }
        return res;
    }

    bool check(int a, int b, int x, int y, int r) {
    int d = (a-x)*(a-x) + (b-y)*(b-y);
           if (d > r*r) return false;
        return true;
    }
};