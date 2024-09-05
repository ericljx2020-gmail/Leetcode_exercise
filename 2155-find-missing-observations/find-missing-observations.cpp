class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> res;
        int m = rolls.size();
        int tot = mean * (n+m);
        int sum = 0;
        for (auto c : rolls) sum += c;
        int diff = tot-sum;
        if (diff < n * 1|| diff > n * 6) return {};
        while (diff){
            if (diff - 6 >= n-1){
                diff -= 6;
                res.push_back(6);
                n --;
            }else{
                res.push_back(diff-n+1);
                diff -= (diff-n+1);
                while (diff--){
                    res.push_back(1);
                }
                break;
            }
        }
        return res;
    }
};