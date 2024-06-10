class Solution {
public:
    string largestMerge(string s1, string s2) {
        int i = 0, j = 0;
        int n = s1.size(), m = s2.size();
        string merge = "";
        while (i < n && j < m){
            if (s1[i] < s2[j]){
                merge += s2[j];
                j++;
            }else if (s1[i] > s2[j]){
                merge += s1[i];
                i++;
            }else{
                if (s1.substr(i) > s2.substr(j)){
                    merge += s1[i];
                    i++;
                }else if (s1.substr(i) <= s2.substr(j)){
                    merge += s2[j];
                    j++;
                }
            }
        }
        merge += s1.substr(i);
        merge += s2.substr(j);
        return merge;
    }
};