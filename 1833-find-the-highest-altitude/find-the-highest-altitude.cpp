class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        gain.insert(gain.begin(), 0);
        vector<int> f(n+1, 0);
        int p = 0;
        for (int i = 1; i <= n; i++){
            f[i] = f[i-1] + gain[i];
            p = max(p, f[i]);
        }
        return p;
    }
};