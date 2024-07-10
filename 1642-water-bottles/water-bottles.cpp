class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0;
        int tot = 0;
        while (numBottles){
            empty += numBottles;
            tot += numBottles;
            numBottles = empty / numExchange;
            empty = empty % numExchange;
        }
        return tot;
    }
};