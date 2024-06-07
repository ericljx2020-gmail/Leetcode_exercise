class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        int sum = 0;
        for (auto d : digits){
            sum += d;
        }
        int mod = sum % 3;
        string res = "";
        if (mod == 0){
            for (auto d : digits){
                res += to_string(d);
            }
            reverse(res.begin(), res.end());
            if (res[0] == '0') return "0";
            return res;
        }
        unordered_set<int> p;
        for (int i = 0; i < digits.size(); i++){
            if (digits[i] % 3 == mod){
                p.insert(i);
                break;
            }
        }
        if (!p.size()){
            if (mod == 1) mod = 2;
            else mod = 1;

            for (int i = 0; i < digits.size(); i++){
                if (digits[i] % 3 == mod && p.size() < 2){
                    p.insert(i);
                    // break;
                }
            }            
        }

        for (int i = 0; i < digits.size(); i++){
            res += (p.find(i) == p.end()) ? to_string(digits[i]) : "";
        }

        reverse(res.begin(), res.end());
        // cout << res.substr(0,1);
        if (res[0] == '0') return "0";
        return res;
    }
};