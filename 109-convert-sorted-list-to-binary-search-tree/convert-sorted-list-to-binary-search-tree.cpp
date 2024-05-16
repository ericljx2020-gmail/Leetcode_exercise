/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        auto p = head;
        while (p){
            v.push_back(p -> val);
            p = p -> next;
        }

        // for (auto a : v) cout << a << ' ';

        return build(0,v.size()-1, v);
    }

    TreeNode* build(int l, int r, vector<int> v) {
        if (l > r) return NULL;
        int pos = l + r >> 1;
        // cout << l << " " << r << " " << pos << '\n';
        auto p = new TreeNode(v[pos]);
        p -> left = build(l, pos-1, v);
        p -> right = build(pos+1, r, v);
        return p;
    }
};