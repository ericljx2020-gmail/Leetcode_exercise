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
    unordered_map<long long, int> hash;
    int res = 0;
    int t;
    int pathSum(TreeNode* root, int targetSum) {
        hash[0] = 1;
        t = targetSum;
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* p, long long s){
        //dfs 走的永远是从root到当前节点的一条路，所以可以用前缀和+回溯来做
        if (!p) return ;
        s += p -> val;
        res += hash[s - t];
        hash[s]++;
        dfs(p -> left, s);
        dfs(p -> right, s);
        hash[s]--;
    }
};