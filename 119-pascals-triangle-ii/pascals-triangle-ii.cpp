typedef long long ll;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res;
        res.push_back(1);
        ll prev = 1;

        for (int i = 1; i <= rowIndex; i++){
            res.push_back(prev * (rowIndex-i+1) / i);
            prev = prev * (rowIndex - i + 1) / i;
        }
        return res;
    }
};