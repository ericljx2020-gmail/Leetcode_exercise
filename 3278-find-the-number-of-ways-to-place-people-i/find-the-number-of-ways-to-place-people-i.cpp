class Solution {
public:
    const int N = 55;
    int numberOfPairs(vector<vector<int>>& points) {
        vector<vector<int>> board(N, vector<int> (N, 0)), f(N, vector<int> (N, 0));
        for (auto p : points){
            board[p[0]][p[1]] = 1;
        }
        int res = 0;
        for (int i = 0; i < points.size(); i++){
            for (int j = 0; j < points.size(); j++){
                if (i == j) continue;
                int x = points[i][0], y = points[i][1];
                int a = points[j][0], b = points[j][1];
                //假设i是在左上角，j是在右下角
                int cnt = 0;
                // cout << x << " " << y << " " << a << " " << b << '\n';
                bool flag = true, in = false;
                for (int k = x; k <= a; k++){
                    for (int d = b; d <= y; d++){
                        in = true;
                        cnt += board[k][d];
                        if (cnt > 2) flag = false;
                    }
                }
                if (flag && in) res++;
            }
        }
        return res;
    }
};