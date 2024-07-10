class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for (auto log : logs){
            if (log == "../"){
                cnt = max(cnt-1, 0);
            }else if(log == "./"){
                continue;
            }else{
                cnt++;
            }
        }
        return cnt;
    }
};