class Solution {
public:
    string getPermutation(int n, int k) {
        /*
            思路跟第k大数有一些相似点。
            e.g n=6,k=10;
            _ _ _ _ _ _ 第一个数填1的话有5！种填法，如果填2也有5！种
            所以第10个数的第一位一定是2，以此类推
        */
        string res = "";
        vector<bool> st(n);
        for (int i = 0; i < n; i++) {
            int fact = 1;
            for (int j = 1; j <= n-i-1; j++) fact *= j;
            for (int j = 1; j <= n; j++){
                if (st[j]) continue;
                if (fact < k) k -= fact;
                else{
                    // 如果fact加起来还没有到k说明当前为放j不行
                    //如果fact大于的话说明当前位取j但是不减
                    res += to_string(j);
                    st[j] = 1;
                    break;
                }
            }
        }
        return res;
    }
};