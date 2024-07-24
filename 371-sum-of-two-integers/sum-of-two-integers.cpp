class Solution {
public:
    int getSum(int a, int b) {
        int t = 0;
        int res = 0;
        for (int i = 0; i < 32; i++){
            int ai = a >> i & 1, bi = b >> i & 1;
            if (ai == 1 && bi == 1){
                res |= t << i;
                t = 1;
            }else if (ai == 1 || bi == 1){
                res |= (t ^ 1) << i;
            }else{
                res |= t << i;
                t = 0;
            }
        }
        return res;
    }
};