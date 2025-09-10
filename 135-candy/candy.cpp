class Solution {
public:
    int candy(vector<int>& a) {
        int inc = 1, top = 1, dec = 1;
        int res = 1;
        int n = a.size();
        for (int i = 1; i < n; i++){
            if (a[i] > a[i-1]){
                // uphill
                inc++;
                res += inc;
                dec = 1;
                top = inc;
            }else if (a[i] == a[i-1]){
                top = 1;
                inc = 1;
                dec = 1;
                res += 1;
            }else{
                inc = 1;
                dec ++;
                res += (dec-1);
                if (dec > top){
                    res += 1;
                }
            }
        }
        return res;
    }
};