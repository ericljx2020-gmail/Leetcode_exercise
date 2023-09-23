class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> f;
        bool flag = 0;
        for (int i = 1; i * i <= n; i++){
            if (n % i == 0) {
                f.push_back(i);
                if (n / i == i) flag = 1;
                cout << i << " ";
            }
        }
        if (k <= f.size()) return f[k-1];
        else{
            int r = k-(int)f.size();
            if (flag) r++;
            if ((int)f.size()-r < 0) return -1;
            int c = f[f.size()-r];
            return n / c;
        }
    }
};