class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> dec(n,0), inc(n,0);
        for (int i = 0; i < security.size(); i++) {
            if (i == 0 || security[i] > security[i-1]){
                dec[i] = 1;
            }else{
                dec[i] = dec[i-1]+1;
            }
            // cout << dec[i] << ' ';
        }
        // puts("");
        for (int i = security.size()-1; i >= 0; i--){
            if (i == security.size()-1 || security[i] > security[i+1]){
                inc[i] = 1;
            }else{
                inc[i] = inc[i+1]+1;
            }
        }
        // for (int i = 0; i < n; i++) cout << inc[i] << " ";
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (i < time || i >= n-time) continue;
            if (dec[i] >= time+1 && inc[i] >= time+1) res.push_back(i);
        }

        return res;
    }
};