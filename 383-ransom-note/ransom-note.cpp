class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag, ran;
        int n = ransomNote.size(), m = magazine.size();

        for (int i = 0; i < m; i++) {
            mag[magazine[i]] ++;
        }

        for (int i = 0; i < n; i++){
            if (ran[ransomNote[i]] < mag[ransomNote[i]]){
                ran[ransomNote[i]] ++;
            }else{
                return false;
            }
        }

        return true;
    }
};