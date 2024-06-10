class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int minv = INT_MAX;
        for (auto c : nums){
            minv = min(minv, c);
        }
        int cnt = 0;
        for (auto c : nums){
            cnt += c == minv;
        }

        if (cnt == 1){
            return 1;
        }else{
            //看可否构造小雨minv的数，如果可以构造那么也可以是1
            for (auto c : nums){
                if (c % minv){
                    return 1;
                }
            }

            //如果不行，那么就是用最小的把大于自己的一个一个消除掉，再与自己消除
            //消除大于自己的不耗费，和自己一样的互相消除会生成0，不能消除
            return (cnt+1) / 2;
        }
    }
};