class Solution {
public:
    int findTheWinner(int n, int k) {
        unordered_map<int, bool> st;
        int p = -1;
        int cnt = 0;
        while(true){
            int d = k;
            if (cnt == n-1) break;
            while(d){
                p++;
                if (!st[1+p % n]){
                    d--;
                    // cout << 1+p%n << " ";
                }
            }
            st[1+p % n] = 1;
            // cout << 1+p % n << " ";
            // puts("");
            cnt++;
        }
        for (int i = 1; i <= n; i++){
            if (!st[i]) return i;
        }
        return -1;
    }
};