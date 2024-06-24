class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        //dp思路：可以枚举第i个房子，求最大利润
        //f[i+1]: 销售编号0-i的最大利润
        //考虑两种情况
        //1.第i个房屋卖 f[i+1] = max(f[start[i]] + gold[i]);
        //注释：相当于遍历，所有以i结尾的offer，f[start[i]]相当于遍历所有以i结尾的offer看i被哪一个offer买入的利润最大
        //2.第i个房屋不卖的话 f[i+1] = f[i];
        //两者取最大值即可
        //先按照endi group一下，这样可以减少遍历次数
        vector<vector<pair<int,int>>> groups(n);
        for (auto offer : offers){
            groups[offer[1]].push_back({offer[0], offer[2]});
        }
        // int n = offers.size();
        vector<int> f(n+1, 0);
        for (int i = 0; i < n; i++){
            f[i+1] = f[i];
            for (auto [x,y] : groups[i]){
                f[i+1] = max(f[i+1], f[x] + y);
            }
        }
        return f[n];
    }
};