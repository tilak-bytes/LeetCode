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
    int ans = 0;

    pair<int, int> pleaseSolve(TreeNode* root) {
        if(!root) return {0, 0};

        auto left = pleaseSolve (root -> left);
        auto right = pleaseSolve(root -> right);

        int totalSum = left.first + right.first + root -> val;
        int totalCount = left.second + right.second + 1;

        if(totalSum / totalCount == root -> val) ans++; 

        return {totalSum, totalCount};
    }
    int averageOfSubtree(TreeNode* root) {
        pleaseSolve(root);

        return ans;
    }
};