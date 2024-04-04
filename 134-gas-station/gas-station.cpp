class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++){
            gas.push_back(gas[i]);
            cost.push_back(cost[i]);
        }
        int l = 0;
        int cur_fuel = 0;
        for (int i = 0; i < 2*n; i++){
            cur_fuel += gas[i];
            if (cur_fuel < cost[i]){
                cur_fuel = 0;
                l = 0;
            }else{
                l++;
                cur_fuel -= cost[i];
            }
            if (l >= n) return i-n+1;
        }
        return -1;
    }
};