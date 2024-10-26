class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++){
            int p = -1;
            char maxv = s[i]+1;
            for (int j = i+1; j < s.size(); j++){
                if (s[j] > s[i]){
                    if (s[j] >= maxv){
                        maxv = s[j];
                        p = j;
                    }
                }
            }
            if (p == -1) continue;
            swap(s[i], s[p]);
            return stoi(s);
        }
        return num;
    }
};