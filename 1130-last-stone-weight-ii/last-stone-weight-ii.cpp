class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int t = sum / 2;
        vector<int> f(t+1, 0);
        f[0] = 1;
        int maxv = 0;
        for (auto stone : stones){
            for (int i = t; i >= stone; i--){
                f[i] = f[i] | f[i-stone];
                if (f[i] == 1) maxv = max(maxv, i);
            }
        }
        for (int i = 0; i <= t; i++) cout << f[i] << " ";
        if (maxv == t){
            return (int) (sum & 1);
        }else{
            return sum - 2 * (maxv);
        }
    }
};