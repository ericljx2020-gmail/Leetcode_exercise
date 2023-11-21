class Solution {
public:
    const long long MOD = 1e9+7;
    int rev(int a){
        while (a != 0 && a % 10 == 0){
            a /= 10;
        }

        int r = 0;
        while (a){
            r *= 10;
            r += a % 10;
            a /= 10;
        }
        return r;
    }
    long long choose(long long n){
        //compute nC2
        return (n*(n-1))/2 % MOD;
    }
    int countNicePairs(vector<int>& nums) {
        vector<int> reverse, d;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            reverse.push_back(rev(nums[i]));
            d.push_back(nums[i]-reverse[i]);
        }
        unordered_set<int> e;
        unordered_map<long long,long long> hash;
        for (int i = 0; i < n; i++){
            e.insert(d[i]);
            hash[d[i]]++;
        }
        // cout << n << "\n";
        long long res = 0;
        for (auto ele : e){
            // cout << hash[ele] << " ";
            res += choose(hash[ele]) % MOD;
        }
        return res % MOD;
    }
};