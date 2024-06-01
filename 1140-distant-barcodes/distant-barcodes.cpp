class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        int n = b.size();
        vector<int> v(n, 0); 
        unordered_map<int, int> hash;
        
        for (int i = 0; i < b.size(); i++){
            hash[b[i]]++;
        }
        vector<pair<int,int>> p;
        for (auto c : hash){
            p.push_back({c.first, c.second});
        }
        sort(p.begin(), p.end(), cmp);
        // for (auto a : p) cout << a.first << " ";
        int idx = 0;
        bool flag = true;
        for (int i = 0; i < p.size(); i++){
            while (idx < n && p[i].second){
                v[idx] = p[i].first;
                p[i].second--;
                idx += 2;
                if (idx >= n && flag) {
                    idx = 1;
                    flag = false;
                } 
            }
        }
        return v;
    }

    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    }
};