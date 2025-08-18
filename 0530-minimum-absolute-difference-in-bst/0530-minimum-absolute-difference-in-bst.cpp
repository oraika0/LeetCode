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

 //inorder
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int min = INT_MAX;
        TreeNode* prev = nullptr;
        rec(root, min, prev);
        return min;
    }
    void rec(TreeNode* root, int& min, TreeNode*&  prev){
        if (root->left){
            rec(root->left, min, prev);
        }
        if (prev){
            // cout << root->val << " " << prev->val << " " << min << endl;
            min = std::min(root->val - prev->val, min);
        }
        prev = root;
        
        // cout << root->val;
        if (root->right){
            rec(root->right,min, prev);
        }
    }
};