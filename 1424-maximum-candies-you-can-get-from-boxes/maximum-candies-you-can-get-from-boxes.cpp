class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        unordered_map<int, bool> has_key, st;

        queue<int> q;
        for (auto c : initialBoxes){
            q.push(c);
            st[c] = 1;
        }
        int res = 0;
        int cnt = 0;
        while (q.size()){
            auto t = q.front();
            q.pop();
            // cout << t << " ";
            if (has_key[t] || status[t]){
                res += candies[t];
                cnt = 0;
            }else{
                q.push(t);
                cnt++;
                if (cnt >= q.size()) return res;
                continue;
            }

            //add keys
            for (auto k : keys[t]){
                has_key[k] = 1;
            }

            //pushbox
            for (auto b : containedBoxes[t]){
                if (!st[b]){
                    q.push(b);
                    st[b] = 1;
                }
            }

        }
        return res;

    }
};