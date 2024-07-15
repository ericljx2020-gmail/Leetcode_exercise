class Solution {
public:
    int maxConsecutiveAnswers(string arr, int k) {
        int res = 0;
        int tt = 0, ff = 0;
        int n = arr.size();
        //第一次做全是T的，如果超过k个ff就不行
        for (int i = 0, j = 0; i < n; i++){
            if (arr[i] == 'F'){
                while (j < i && ff == k){
                    ff -= (arr[j] == 'F');
                    j++;
                }
                ff++;
            }
            res = max(res, i-j+1);
        }
        for (int i = 0, j = 0; i < n; i++){
            if (arr[i] == 'T'){
                while (j < i && tt == k){
                    tt -= (arr[j] == 'T');
                    j++;
                }
                tt++;
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};