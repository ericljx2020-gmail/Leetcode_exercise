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
    vector<int> res;

    void trav(TreeNode* p){
        if (!p) return ;
        trav(p -> left);
        res.push_back(p -> val);
        trav(p -> right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        trav(root);
        return res;
    }
};