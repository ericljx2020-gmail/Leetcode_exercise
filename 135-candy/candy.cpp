class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        int inc = 1, dec = 1, top = 1;
        int res = 1;
        for (int i = 1; i < n; i++){
            if (a[i] > a[i-1]) {
                //  uphill
                inc++;
                dec = 1;
                res += inc;
                top = inc;
            }else if (a[i] == a[i-1]) {
                inc = 1;
                dec = 1;
                top = 1;
                res += inc;
            }else{
                inc = 1;
                dec++;
                res += (dec-1);
                if (dec > top) res ++;
            }
        }

        return res;

    }
};