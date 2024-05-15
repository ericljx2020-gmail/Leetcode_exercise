class Solution {
public:
    int numTrees(int n) {
        return dfs(1,n);
    }

    int dfs(int l, int r) {
        if (l >= r) return 1;
        int cur = 0;
        for (int i = l; i <= r; i++) {
            cur += dfs(l,i-1) * dfs(i+1, r);
        }
        return cur;
    }
};