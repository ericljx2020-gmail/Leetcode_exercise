class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        //由于每一个字母只会出现一次，相当于判断两个单词是否由相同字母组成只需要给字母排一个序就可以
        //这里可以用位运算省去排序操作，对于targetwords每一个string只需要枚举去掉每一个字母是否在startwords里面就可以了
        unordered_set<int> s;
        for (auto word : startWords){
            int mask = 0;
            for (auto ch : word){
                mask |= 1 << (ch - 'a');
            }
            s.insert(mask);
        }
        int res = 0;
        for (auto word : targetWords){
            int mask = 0;
            for (auto ch : word){ 
                mask |= 1 << (ch - 'a');
            }

            for (auto ch : word){
                if (s.count(mask ^ 1 << (ch-'a'))) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};