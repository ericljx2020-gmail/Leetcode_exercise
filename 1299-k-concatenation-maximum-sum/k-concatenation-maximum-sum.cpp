class Solution {
public:
    const int MOD = 1e9+7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        //分类别讨论
        //1. k = 1, 那么就是经典的subarray max问题
        //2. sum(arr) > 0: k-2 * sum(arr) + max(prefix) + max(suffix)
        //3. sum(arr) <= 0, 说明连起来多段没有用，答案只可能在一个arr里或者两个arr里
        long long sum = 0, maxv = 0, pfx = 0, suf = 0, s = 0;
        for (int i = 0; i < arr.size(); i++){
            sum += arr[i];
            pfx = max(pfx, sum);
            s = max(s, 0ll) + arr[i];
            maxv = max(maxv, s);
            if (i == arr.size()-1) suf = s;
        }

        if (k == 1) return (int) maxv;
        if (sum > 0) return (int) (((k-2) * sum) % MOD + pfx + suf) % MOD;
        return (int)max(pfx+suf, maxv);
    }
};