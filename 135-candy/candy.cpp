class Solution {
public:
    int candy(vector<int>& ratings) {
        int asc = 0, dec = -1, dec_max = 1;
        int res = 0;
        for (int i = 0; i < ratings.size(); i++){
            if (i == 0 || ratings[i] > ratings[i-1]) {
                asc++;
                res += asc;
                dec = -1;
            }else if (ratings[i] < ratings[i-1]){
                if (dec == -1){
                    //this is the second of dec sequence, including the last one in asc
                    dec = 1;
                    dec_max = asc;
                }else{
                    dec++;
                }
                if (dec == dec_max){
                    res = res + dec + 1;
                    dec_max++;
                }else{
                    res += dec;
                }
                asc = 1;
            }else{
                //equal
                dec_max = 1;
                asc = 1;
                dec_max = 1;
                res += asc;
            }
        }
        return res;
    }
};