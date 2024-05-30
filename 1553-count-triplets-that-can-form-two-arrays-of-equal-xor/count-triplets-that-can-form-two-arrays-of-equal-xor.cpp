class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        arr.insert(arr.begin(), 0);
        vector<int> f(n+1, 0);
        for (int i = 1; i <= n; i++) {
            f[i] = f[i-1] ^ arr[i];
            cout << f[i] << " ";
        }
        int res = 0;
        for (int i = 1; i < n; i++){
            for (int j = i+1; j <= n; j++){
                for (int k = j; k <= n; k++){
                    int q1 = f[j-1] ^ f[i-1];
                    int q2 = f[k] ^ f[j-1];
                    if (q1 == q2) res++;
                }
            }
        }
        return res;
    }
};