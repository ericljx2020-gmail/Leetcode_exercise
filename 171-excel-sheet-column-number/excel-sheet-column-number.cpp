class Solution {
public:
    int titleToNumber(string columnTitle) {
        if (columnTitle.size() == 1){
            return columnTitle[0] - 'A' + 1;
        }

        int idx = 0;
        int res = 0;

        unordered_map<char, int> hash;

        for (char i = 'A'; i <= 'Z'; i++){
            hash[i] = (int)i-'A'+1;
        }

        while (idx < columnTitle.size()){
            int c = hash[columnTitle[idx++]];
            cout << c << " ";
            res *= 26;
            res += c;
        }
        return res;
    } 
};