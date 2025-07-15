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

 // try to slice the inorder vector with start and end pointers 
 // start is the begining index of the slicing inorder vector
 // end is the end index+1 of the slicing inorder vector
 // => if start == end => empty slicing 
 // => if end - start = 1 => only one element in the slicing
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0){
            return nullptr;
        }
        int currPreNum = 0;

        return recur(preorder,inorder,currPreNum,0,preorder.size());
    }
    TreeNode* recur(vector<int>& preorder, vector<int>& inorder,int& currPreNum,int start, int end) {
        if (end - start  == 0){
            return nullptr;
        }

        TreeNode* currNode = new TreeNode(preorder[currPreNum]);
        // find currNode position in inorder vector
        int pos = start;
        for (int i = start; i < end; i++){
            if (inorder[i] == preorder[currPreNum]){
                pos = i;
                break;
            }
        }
        currPreNum++;
        // devide and concour with two partial slicing
        currNode->left = recur(preorder,inorder,currPreNum,start,pos);
        currNode->right = recur(preorder,inorder,currPreNum,pos+1,end);
        return currNode;
    }
};