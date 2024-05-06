class Solution {
public:
    int divide(int dividend, int divisor) {
        if (abs(divisor) == 1){
            if (dividend == INT_MIN && divisor == -1) return (dividend+1) * divisor;
            return dividend * divisor;
        }
        return dividend / divisor;
    }
};