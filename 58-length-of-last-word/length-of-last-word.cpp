class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int t = n-1;
        int l = 0;
        bool start = 0;
        while (t >= 0){
            if (start){
                if (s[t] == ' ') return l;
                else{
                    l++;
                }
            }else{
                if (s[t] != ' '){
                    start = true;
                    l = 1;
                }
            }
            t--;
        }
        return l;
    }
};