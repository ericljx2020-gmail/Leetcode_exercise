class Solution {
public:
    char findKthBit(int n, int k) {
        int flip = 0;
        while (n > 2){
            int p = pow(2, n);
            if (k > p/2){
                k = p - k;
                flip = 1-flip;
                cout << k << " ";
            }else if (k == p/2){
                return flip == 0 ? '1' : '0';
            }
            n--;
        }
        cout << flip;
        if (k == 1) return flip == 0 ? '0' : '1';
        else return flip == 0 ? '1' : '0';
    }
};