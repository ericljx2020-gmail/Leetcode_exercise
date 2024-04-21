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
    int res = 0;
    void findRoot(TreeNode* cur, int sum) {
        if (!cur) {
            return;
        }
        sum *= 10;
        sum += cur -> val;
        cout << cur -> val << " " << sum << '\n';
        if ((!cur -> left) && (!cur -> right)) {
            res += sum;
            return;
        }
        findRoot(cur -> left, sum);
        findRoot(cur -> right, sum);
        
    }

    int sumNumbers(TreeNode* root) {
        findRoot(root, 0);
        return res;
    }
};