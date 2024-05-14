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
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1,n);
    }

    vector<TreeNode*> dfs(int l, int r){
        if (l > r) return {NULL};
        vector<TreeNode*> cur;
        for (int i = l; i <= r; i++){
            auto left = dfs(l,i-1), right = dfs(i+1,r);
            for (auto ll : left) {
                for (auto rr : right) {
                    auto p = new TreeNode(i);
                    p -> left = ll;
                    p -> right = rr;
                    cur.push_back(p);
                }
            }
        }
        return cur;
    }
};