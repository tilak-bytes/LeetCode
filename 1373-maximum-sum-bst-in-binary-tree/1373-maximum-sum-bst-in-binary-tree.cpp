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

class NodeInfo {
    public: 

    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};

class Solution {
public:

    NodeInfo solve(TreeNode* root, int& ans) {
        if(root == NULL) return {true, INT_MAX, INT_MIN, 0};

        NodeInfo left = solve(root -> left, ans);
        NodeInfo right = solve(root -> right, ans);

        if(left.isBST && right.isBST && 
            (left.maxVal < root -> val && right.minVal > root -> val)) {

            int sum = left.sum + right.sum + root -> val;
            ans = max(ans, sum);

            return {true, 
                min(left.minVal, root -> val), 
                max(right.maxVal, root -> val),
                sum};
        }
        return {false, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};