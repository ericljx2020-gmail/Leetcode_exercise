class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int len = 0;
        for (int i = 0; i < words.size(); i++) {
            len = words[i].size();
            int j = i + 1;
            while (j < words.size() && len + 1 + words[j].size() <= maxWidth) {
                len += 1 + words[j++].size();
            }
            //j-1是最后一个可以放在这一行的单词
            string line;
            line = words[i];
            int k = i + 1;
            if (len == words[i].size() || j == words.size()) {
                //如果是最后一行或者一行只有一个单词的话，左对齐
                while (k < j) {
                    line += " ";
                    line += words[k];
                    k++;
                }
                while (line.size() < maxWidth) line += " ";
            }else{
                //居中对齐
                //求总共空格的数量
                int spc = j-i-1;            //3个单词2个空格
                int r = (maxWidth - len + spc) % spc;     //余数
                int c = (maxWidth - len + spc) / spc;     //每一个基本的数量
                int l = 0;
                while (l < r){
                    line += string(c+1, ' ') + words[i+l+1];
                    l++;
                }
                while (l < spc) {
                    line += string(c, ' ') + words[i+l+1];
                    l++;
                }
            }

            res.push_back(line);
            i = j-1;
        }

        return res;
    }
};