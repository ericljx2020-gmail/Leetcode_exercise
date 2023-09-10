class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0 && right == 0) return 0;
        if (left == right) return left;
        int lf = left, rt = right;
        int l = 0, r = 0;
        while (left || right){
            if (left) l++;
            if (right) r++;
            left >>= 1;
            right >>= 1;
        }
        // cout << l << " " << r;
        if (l != r) return 0;
        int mark = 0;
        for (int i = l-1; i >= 0; i--){
            if ((lf >> i) != (rt >> i)) {
                mark = i+1;
                break;
            }
        }
        cout << mark << endl;
        int mask = (1 << mark)-1;
        cout << mask;
        mask = ~mask;
        return lf & mask;

    }
};