class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n = customers.size();
        int q[100000];
        int tt = -1, hh = 0;
        int orig = 0;
        int add = 0;
        int maxadd = 0;
        for (int i = 0; i < n; i++){
            orig += (1-grumpy[i]) * customers[i];
        }
        // cout << orig;
        for (int i = 0; i < n; i++){
            if (hh <= tt && q[hh] < i-k+1){
                add -= (grumpy[q[hh]] == 1) * customers[q[hh++]];
            }
            q[++tt] = i;
            add += (grumpy[i] == 1) * customers[i];
            maxadd = max(maxadd, add);
        }
        return orig + maxadd;
    }
};