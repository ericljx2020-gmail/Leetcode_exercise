class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> dif(n, 0);
        for (int i = 0; i < n; i++) dif[i] = gas[i] - cost[i];
        for (int i = 0; i < n; i++) dif.push_back(dif[i]);

        for (int i = 0; i < dif.size(); i++){
            int cur = dif[i];
            int j = i;
            while (j+1 < dif.size() && cur >= 0){
                j++;
                cur += dif[j];
            }
            cout << j << " " << i << endl;
            if (j - i >= gas.size()) return i;
            i = j;

        }
        return -1;
    }
};