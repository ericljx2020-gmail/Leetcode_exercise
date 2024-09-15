class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res;
        res.push_back(1);
        vector<int> p(primes.size(), 0);
        for (;res.size() < n;){
            long long Min = INT_MAX;
            for (int i = 0; i < primes.size(); i++){
                Min = min(Min, (long long)primes[i] * res[p[i]]);
            }
            for (int i = 0; i < primes.size(); i++){
                if (Min == primes[i] * (long long)res[p[i]]) p[i]++;
            }
            res.push_back((int)Min);
        }
        return res[res.size()-1];
    }
};