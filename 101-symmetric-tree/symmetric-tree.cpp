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
    vector<int> left, right;
    void inorderL(TreeNode* p) {
        if (!p) {
            left.push_back(-1);
            return;
        }
        left.push_back(p -> val);
        inorderL(p -> left);
        inorderL(p -> right);
    }

    void inorderR(TreeNode* p) {
        if (!p) {
            right.push_back(-1);
            return;
        }
        right.push_back(p -> val);
        inorderR(p -> right);
        inorderR(p -> left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        inorderL(root -> left);
        inorderR(root -> right);
        if (left.size() != right.size()) return false;
        for (int i = 0; i < left.size(); i++){
            if (left[i] != right[i]) return false;
            // cout << left[i] << " " << right[i] << "\n";
        }
        return true;
    }
};