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

    void getinorder(vector<int>& inorder, TreeNode* root){
        if(root == NULL) return;

        getinorder(inorder, root -> left);
        inorder.push_back(root -> val);
        getinorder(inorder, root -> right);
    }

    void correctTree(int& index, vector<int>& correctOrder, TreeNode* root) {
        if(root == NULL) return;

        correctTree(index, correctOrder, root -> left);
        root -> val = correctOrder[index++];
        correctTree(index, correctOrder, root -> right);
    }

    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        getinorder(inorder, root);

        vector<int> correctOrder = inorder;
        sort(correctOrder.begin(), correctOrder.end());

        int index = 0;
        correctTree(index, correctOrder, root);
    }
};