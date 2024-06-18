class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int,int>> v;
        unordered_map<int, int> hash;
        for (int i = 0; i < d.size(); i++){
            v.push_back({d[i], p[i]});
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < d.size(); i++){
            if (i == 0) {
                hash[v[i].first] = v[i].second;
                cout << hash[v[i].first] << " ";
                continue;
            }
            hash[v[i].first] = max(hash[v[i].first], max(hash[v[i-1].first], v[i].second));
            // cout << hash[v[i].first] << " ";
        }

        sort(d.begin(), d.end());
        int res = 0;
        for (auto c : w){
            int x = find(c, d);
            if (d[x] <= c){
                res += hash[d[x]];
            }
        }

        return res;
    }

    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    }

    int find(int x, vector<int> d){
        int l = 0, r = d.size()-1;
        while (l < r ){
            int mid = l + r + 1 >> 1;
            if (d[mid] <= x){
                l = mid;
            }else{
                r = mid-1;
            }
    }
        return r;
    }
};