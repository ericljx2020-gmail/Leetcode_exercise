class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int l = 0, r = 1e9;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (check(mid, n, k, budget, composition, stock, cost)){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return r;
    }

    bool check(int p,int n, int k, int budget, vector<vector<int>> composition, vector<int> stock, vector<int> cost){
        for (int i = 0; i < k; i++){
            long long price = 0;
            for (int j = 0; j < n; j++){
                price += max(0ll,((long long)composition[i][j]*p-stock[j]) * cost[j]);
            }
            if (price <= budget) return true;
        }
        return false;
    }
};