class Solution {
public:

    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int, int>> v;
        for (int i = 0; i < profits.size(); i++){
            v.push_back({profits[i], capital[i]});
        }
        sort(v.begin(), v.end(), cmp);

        int idx = 0;
        int ans = 0;
        while (k --){
            while (idx < profits.size() && w >= v[idx].second){
                pq.push(v[idx].first);              // if capital needed is less than we have, we push all possible profits into the maxheap
                idx++;
            }
            if (pq.size() == 0) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};