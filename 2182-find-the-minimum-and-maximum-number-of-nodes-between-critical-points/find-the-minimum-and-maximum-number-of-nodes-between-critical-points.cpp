/**
 * Definition for singly-linked list.
 * struct ListNode 
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        auto p = head;
        vector<int> v;
        while (p){
            v.push_back(p -> val);
            p = p -> next;
        }
        int previous = -1;
        int first = -1;
        int last = -1;
        int minD = INT_MAX;
        int maxD = INT_MIN;
        for (int i = 1; i < v.size()-1; i++){
            if ((v[i] < v[i-1] && v[i] < v[i+1]) || (v[i] > v[i-1] && v[i] > v[i+1])){
                //is a critical point
                if (previous == -1){
                    first = i;
                    previous = i;
                    continue;
                }else{
                    minD = min(minD, i - previous);
                    previous = i;
                    last = max(last, i);
                }
            }
        }
        maxD = last - first;
        if (minD == INT_MAX) minD = -1;
        if (last == -1) maxD = -1;
        return {minD, maxD};
        
    }
};