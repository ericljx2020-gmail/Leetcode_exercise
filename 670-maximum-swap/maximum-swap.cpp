class Solution {
public:
    int maximumSwap(int num) {
        string cp = to_string(num);
        for (int i = 0; i < cp.size(); i++){
            char maxv = cp[i]+1;
            int p = -1;
            for (int j = i+1; j < cp.size(); j++){
                if (cp[j] >= maxv){
                    maxv = cp[j];
                    p = j;
                }
            }
            if (p != -1){
                swap(cp[i], cp[p]);
                return stoi(cp);
            }
        }
        return num;
    }
};