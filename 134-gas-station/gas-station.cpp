class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> absolute(n, 0);
        vector<int> prefix(2*n+1, 0);
        for (int i = 0; i < n; i++){
            absolute[i] = gas[i] - cost[i];
        }
        for (int i = 0; i < n; i++){
            absolute.push_back(absolute[i]);
        }
        int l = 0;
        int cur = 0;
        for (int i = 0; i < 2*n; i++) {
            cur += absolute[i];
            if (cur < 0){
                cur = 0;
                l = 0;
            }else{
                l++;
            }
            if (l >= n) return i-l+1;
        }
        return -1;
    }
};