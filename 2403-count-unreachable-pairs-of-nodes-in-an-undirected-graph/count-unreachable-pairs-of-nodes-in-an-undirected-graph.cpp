class Solution {
public:
    unordered_map<int, int> sz;
    vector<int> f;

    int find(int x) {
        if (f[x] == x) return f[x];
        return f[x] = find(f[x]);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        f.resize(n);
        for (int i = 0; i < n; i++) f[i] = i, sz[i] = 1;
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            int fa = find(a), fb = find(b);
            if (fa == fb) continue;
            else{
                f[fa] = fb;
                sz[fb] += sz[fa];
            }
        }
        unordered_map<int, bool> hash;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int fi = find(i);
            if (hash[fi]) continue;
            // cout << sz[fi] << " ";
            hash[fi] = 1;
            res.push_back(sz[fi]);
        }
        long long ans = 0;
        for (int i = 0; i < res.size(); i++) {
            ans += (long long)res[i] * (n-res[i]);
        }
        ans /= 2;
        return ans;
    }
};