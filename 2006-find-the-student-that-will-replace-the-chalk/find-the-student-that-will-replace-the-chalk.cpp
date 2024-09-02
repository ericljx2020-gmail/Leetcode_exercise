class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int idx = 0;
        long long sum = 0;
        for (auto c : chalk){
            sum += c;
        }
        if (k >= sum){
            k %= sum;
        }
        while (k >= 0){
            k -= chalk[idx % n];
            idx++;
        }
        return (idx-1) % n;
    }
};