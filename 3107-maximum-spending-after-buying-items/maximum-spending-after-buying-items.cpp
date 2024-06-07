class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long res = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> >pq;
        int n = values.size(), m= values[0].size();

        for (int i = 0; i < n; i++){
            pq.push({values[i][m-1], {i,m-1}});
        }
        int idx = 1;
        while (pq.size()){
            auto t = pq.top();
            pq.pop();
            int v = t.first, x = t.second.first, y = t.second.second;
            res += (long long)idx * v;
            // cout << idx * v << " " << idx << " " << v << '\n';;
            idx++;
            if (y != 0){
                pq.push({values[x][y-1], {x,y-1}});
            }
        }
        return res;
    }
};