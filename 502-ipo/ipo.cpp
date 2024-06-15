class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int,int>> v;
        int n = profits.size();
        for (int i = 0; i < n; i++){
            v.push_back({profits[i], capital[i]});
        }
        sort(v.begin(), v.end(), cmp);

        // int ans = 0;
        int idx = 0;
        while (k--){
            while (idx < n && v[idx].second <= w){
                pq.push(v[idx].first);
                idx++;
            }
            if (pq.empty()) return w;
            // ans += pq.top();
            w += pq.top();
            pq.pop();
        }
        return w;

    }

    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
};