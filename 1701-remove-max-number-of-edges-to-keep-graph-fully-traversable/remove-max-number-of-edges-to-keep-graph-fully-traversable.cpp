class Solution {
public:
    vector<int> f,g;
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] > b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        f.resize(n+1, -1);
        g.resize(n+1, -1);
        for (int i = 0; i <= n; i++){
            f[i] = i;
            g[i] = i;
        }
        sort(edges.begin(), edges.end(), cmp);
        int res = 0;
        for (auto e : edges){
            int t = e[0], a = e[1], b = e[2];
            int faa = findA(a), fba = findA(b);
            int fab = findB(a), fbb = findB(b);
            if (t == 3){
                //两个人都要加
                if (faa != fba || fab != fbb){
                    f[faa] = fba;
                    g[fab] = fbb;
                    res++;
                }
            }else if (t == 2){
                //加bob
                if (fab != fbb){
                    g[fab] = fbb;
                    res++;
                }
            }else{
                //加alice
                if (faa != fba){
                    f[faa] = fba;
                    res++;
                }
            }
        }
        int fa = findA(1);
        for (int i = 2; i <= n; i++){
            int ffa = findA(i);
            if (ffa != fa) return -1;
        }
        int fb = findB(1);
        for (int i = 2; i <= n; i++){
            int ffb = findB(i);
            if (ffb != fb) return -1;
        }
        return edges.size()-res;
    }
    int findA(int x){
        if (f[x] == x) return x;
        return f[x] = findA(f[x]);
    }
    int findB(int x){
        if (g[x] == x) return x;
        return g[x] = findB(g[x]);
    }
};